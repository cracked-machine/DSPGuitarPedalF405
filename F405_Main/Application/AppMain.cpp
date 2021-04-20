/*
 * AppMain.cpp
 *
 *  Created on: Apr 11, 2021
 *      Author: chris
 */

#include <AppMain.hpp>

// HAL
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include "tim.h"
#include "stm32f4xx_hal_i2s.h"
#include "i2s.h"

#include <new>


// STL
#include <iostream>
#include <array>
#include <assert.h>


#include <pedal_io_test.hpp>

#include <PeriphInterrupts.hpp>
#include <BaseTaskManager.hpp>
#include <StateMachine.hpp>
#include <DSPManager.hpp>
#include <ResourceManager.hpp>

#include <IIRCombFilter.hpp>
#include <UniCombFilter.hpp>



#ifdef __cplusplus
	extern "C"
	{
#endif


	//IIRCombFilter *combfilter1 = new  IIRCombFilter(3460 * 2, 0.805);
	//IIRCombFilter *combfilter2 = new  IIRCombFilter(2988 * 2, 0.827);
	//IIRCombFilter *combfilter3 = new  IIRCombFilter(3882 * 2, 0.783);
	//IIRCombFilter *combfilter4 = new  IIRCombFilter(4312 * 2, 0.764);
	//UniCombFilter *allpass1 = new  UniCombFilter(   480  * 2, 0.7);
	//UniCombFilter *allpass2 = new  UniCombFilter(   161  * 2, 0.7);
	//UniCombFilter *allpass3 = new  UniCombFilter(   46   * 2, 0.7);

	// I2S task declarations
	I2STaskManager_t *i2s_taskman;
	void I2STaskCode( void * parm );
	static StaticQueue_t I2S_StaticQueue;

	// External Control task declarations
	ExtCtrlTaskManager_t *extctrl_taskman;
	void ExtCtrlTaskCode( void * parm );
	static StaticQueue_t ExtCtrl_StaticQueue;
	StateMachine *extctrlMachine = NULL;
	DebounceManager *extctrl_debounceman;



	IIRFilterFx *iirfx;
	//BasicReverb *reverbfx;

	// TODO move this to the stack
	//StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > rxBuf{};
	//StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > txBuf{};

	int32_t myGlobal;

	void appmain()
	{

		std::cout << "Initialising system." << std::endl;



		setupPeriphInterrupts();

		//run_sys_checks();

		//HAL_EnableCompensationCell();


		// I2S task instantiation on the heap at startup
		//
		i2s_taskman = new I2STaskManager_t(200, 1);

		// Set the STATIC freeertos task to global function pointer "I2STaskCode()"
		AbstractTaskPtr_t I2STaskPtr = &I2STaskCode;
		i2s_taskman->setTask("I2STaskManager", I2STaskPtr);

		// Set the STATIC freertos queue
		i2s_taskman->setQueue(&I2S_StaticQueue);
		//

		iirfx = new IIRFilterFx();
		//reverbfx = new  BasicReverb();

		i2s_taskman->setDspManager(new  DSPManager(iirfx));


		// External Control task instantiation on the heap at startup
		//
		extctrl_taskman = new  ExtCtrlTaskManager_t(200, 1);

		// Set the statemachine
		extctrlMachine = new  StateMachine();
		// set the delay for the external control debounce
		extctrl_debounceman = new  DebounceManager(TIM14, 200);
		extctrlMachine->setDebounceMan(extctrl_debounceman);
		extctrl_taskman->setStateMachine(extctrlMachine);


		// Set the STATIC freeertos task to global function pointer "ExtCtrlTaskCode()"
		AbstractTaskPtr_t ExtCtrlTaskPtr = &ExtCtrlTaskCode;
		extctrl_taskman->setTask("ExtCtrlTaskManager", ExtCtrlTaskPtr);

		// Set the STATIC freertos queue
		extctrl_taskman->setQueue(&ExtCtrl_StaticQueue);
		//



		// start FullDuplex I2S DMA
		HAL_StatusTypeDef res = HAL_OK;
		 res = HAL_I2SEx_TransmitReceive_DMA (	&hi2s2,
										i2s_taskman->getDspManager()->txBuf.data(),
										i2s_taskman->getDspManager()->rxBuf.data(),
										AbstractFx::HALF_BLK_SIZE_U16);


/*		 res = HAL_I2SEx_TransmitReceive_DMA (	&hi2s2,
										i2s_taskman->getDspManager()->txBuf.data(),
										i2s_taskman->getDspManager()->rxBuf.data(),
										4);
*/
		if (res != HAL_OK)
			Error_Handler();


		// start the RTOS
		vTaskStartScheduler();

		while(1)
		{
			// not reached!
		}
	}



	// Function that implements the task being created.
	void I2STaskCode( void * parm )
	{
		I2STaskManager_t *_i2s_taskman = static_cast<I2STaskManager_t*>(parm);
		//float wet = 1.0f;


		while(1)
		{
			uint8_t item = 0;
			//std::cout << "I2STaskCode retrieved queue item" << item << std::endl;
			if( ISRQueueReceive( _i2s_taskman->getQueue(), &( item ), ( TickType_t ) 0 ) == pdPASS)
			{
				if(item == 1)
				{
					iirfx->process_half_u16(	&_i2s_taskman->getDspManager()->rxBuf,
												&_i2s_taskman->getDspManager()->txBuf);
/*					for(size_t i = 0; i < i2s_taskman->getDspManager()->rxBuf.size(); i+=4)
					{
						int lSample = (int) (i2s_taskman->getDspManager()->rxBuf[i+0]<<16)|i2s_taskman->getDspManager()->rxBuf[i+1];
						int rSample = (int) (i2s_taskman->getDspManager()->rxBuf[i+2]<<16)|i2s_taskman->getDspManager()->rxBuf[i+3];

						float sum = (float) (lSample + rSample);
						sum = (1.0f - wet ) * sum + wet * reverbfx->processSample(sum);

						lSample = (int) sum;
						rSample = lSample;

						//restore to buffer
						i2s_taskman->getDspManager()->txBuf[i+0] = (lSample>>16)&0xFFFF;
						i2s_taskman->getDspManager()->txBuf[i+1] = lSample&0xFFFF;
						i2s_taskman->getDspManager()->txBuf[i+2] = (rSample>>16)&0xFFFF;
						i2s_taskman->getDspManager()->txBuf[i+3] = rSample&0xFFFF;
					}
*/

					LEDA_G_GPIO_Port->ODR ^= GPIO_ODR_OD1_Msk;
				}
				if(item == 2)
				{
						iirfx->process_full_u16(	&_i2s_taskman->getDspManager()->rxBuf,
												&_i2s_taskman->getDspManager()->txBuf);
/*					for(size_t i = 0; i < i2s_taskman->getDspManager()->rxBuf.size(); i+=4)
					{
						int lSample = (int) (_i2s_taskman->getDspManager()->rxBuf[i+4]<<16)|_i2s_taskman->getDspManager()->rxBuf[i+5];
						int rSample = (int) (_i2s_taskman->getDspManager()->rxBuf[i+6]<<16)|_i2s_taskman->getDspManager()->rxBuf[i+7];

						float sum = (float) (lSample + rSample);
						sum = (1.0f - wet) * sum + wet * reverbfx->processSample(sum);
						lSample = (int) sum;
						rSample = lSample;

						//restore to buffer
						_i2s_taskman->getDspManager()->txBuf[i+4] = (lSample>>16)&0xFFFF;
						_i2s_taskman->getDspManager()->txBuf[i+5] = lSample&0xFFFF;
						_i2s_taskman->getDspManager()->txBuf[i+6] = (rSample>>16)&0xFFFF;
						_i2s_taskman->getDspManager()->txBuf[i+7] = rSample&0xFFFF;
					}
*/
					LEDB_G_GPIO_Port->ODR ^= GPIO_ODR_OD11_Msk;
				}

			}
		}
	}

	/* Function that implements the task being created. */
	void ExtCtrlTaskCode( void * parm )
	{
		ExtCtrlTaskManager_t *_extctrl_taskman = static_cast<ExtCtrlTaskManager_t*>(parm);
		while(1)
		{
			uint16_t item = 0;
			//std::cout << "ExtCtrlTaskCode waiting for queue item" << std::endl;

			if( ISRQueueReceive( _extctrl_taskman->getQueue(), &( item ), ( TickType_t ) 10 ) == pdPASS)
			{
				std::cout << "ExtCtrlTaskCode retrieved queue item" << std::endl;
				switch(item)
				{
					case EXTI_PR_PR13:

						_extctrl_taskman->getStateMachine()->evFootswitchA();
						break;
					case EXTI_PR_PR14:
						_extctrl_taskman->getStateMachine()->evFootswitchB();
						break;
				}
			}
		}
	}



	/*
		extern "C" {

			// The canary value
			extern const uintptr_t __stack_chk_guard = 0xdeadbeef;

			// Called if the check fails
			[[noreturn]]
			void __stack_chk_fail()
			{
				//Error_Handler("Stack overrun!");
				exit(0);
			}

		} // end extern "C"
	*/


	/*
		struct CL {
		    // The bool does nothing, other than making these placement overloads.
		    void* operator new(size_t s, bool b = true);
		    void operator delete(void* o, bool b = true);
		};
		// Functions are simple wrappers for the normal operators.
		void* CL::operator new(size_t s, bool b) { return ::operator new(s); }
		void CL::operator delete(void* o, bool b) { return ::operator delete(o); }
	*/


#ifdef __cplusplus
	}
#endif

