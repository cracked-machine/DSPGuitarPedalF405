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

#include <I2STaskManager.hpp>

#include <StateMachine.hpp>
#include <DSPManager.hpp>
#include <ResourceManager.hpp>

#include <IIRCombFilter.hpp>
#include <UniCombFilter.hpp>

#ifdef USE_FREERTOS
	#include <IIRFilterFx.hpp>

	IIRFilterFx *iirfx;
#endif


#ifdef __cplusplus
	extern "C"
	{
#endif

	#ifdef USE_FREERTOS

		// I2S task declarations
		I2STaskManager_t *i2s_taskman;

		// External Control task declarations
		ExtCtrlTaskManager_t *extctrl_taskman;

		void I2STaskCode( void * parm );
		static StaticQueue_t I2S_StaticQueue;
		void ExtCtrlTaskCode( void * parm );
		static StaticQueue_t ExtCtrl_StaticQueue;

	#else

		I2STskManNoRTOS *i2s_taskman_nortos = nullptr;

	#endif

	StateMachine *statemachine = nullptr;
	DebounceManager *extctrl_debounceman = nullptr;

	DSPManager *dspman = nullptr;

	void appmain()
	{

		ResourceManager rm();
/*
	   while (true) {
			int *t = new int[100000000ul];
		}
*/
		std::cout << std::endl << "-------------------------------------" << std::endl;
		std::cout << "Initialising system." << std::endl;

		std::cout << "System Clock: " << HAL_RCC_GetSysClockFreq() << std::endl;

		std::cout << "I2S Clock: " << HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_I2S) << std::endl;

		std::cout << std::endl << "Beginning heap analysis....." << std::endl;

		setupPeriphInterrupts();

		//HAL_EnableCompensationCell();

		#ifdef USE_FREERTOS
				// I2S task instantiation on the heap at startup
				//
				i2s_taskman = new(std::nothrow) I2STaskManager_t(200, 1);

				// Set the STATIC freeertos task to global function pointer "I2STaskCode()"
				AbstractTaskPtr_t I2STaskPtr = &I2STaskCode;
				i2s_taskman->setTask("I2STaskManager", I2STaskPtr);

				// Set the STATIC freertos queue
				i2s_taskman->setQueue(&I2S_StaticQueue);

				iirfx = new(std::nothrow) IIRFilterFx();
				i2s_taskman->setDspManager(new(std::nothrow)  DSPManager(iirfx));
				//
		#else

		#endif

		#ifdef USE_FREERTOS
				// External Control task instantiation on the heap at startup
				//
				extctrl_taskman = new(std::nothrow)  ExtCtrlTaskManager_t(200, 1);

				// Set the statemachine
				statemachine = new(std::nothrow)  StateMachine();
				// set the delay for the external control debounce
				extctrl_debounceman = new(std::nothrow)  DebounceManager(TIM14, 200);
				statemachine->setDebounceMan(extctrl_debounceman);
				extctrl_taskman->setStateMachine(statemachine);


				// Set the STATIC freeertos task to global function pointer "ExtCtrlTaskCode()"
				AbstractTaskPtr_t ExtCtrlTaskPtr = &ExtCtrlTaskCode;
				extctrl_taskman->setTask("ExtCtrlTaskManager", ExtCtrlTaskPtr);

				// Set the STATIC freertos queue
				extctrl_taskman->setQueue(&ExtCtrl_StaticQueue);
				//
		#else

				// create Task Manager
				i2s_taskman_nortos = new(std::nothrow) I2STskManNoRTOS();

				// create DSP Manager and set it in Task Manager
				dspman = new(std::nothrow)  DSPManager();


				if(i2s_taskman_nortos == nullptr) ResourceManager::notifySysNullPtr< I2STskManNoRTOS >();

				i2s_taskman_nortos->setDspManager(dspman);

				// create StateMachine and set in Task Manager
				statemachine = new(std::nothrow)  StateMachine();

				if(statemachine == nullptr) ResourceManager::notifySysNullPtr< StateMachine >();

				i2s_taskman_nortos->setStateMachine(statemachine);

				// create Debounce Manager and set in StateMachine
				extctrl_debounceman = new(std::nothrow)  DebounceManager(TIM14, 200);

				if(statemachine == nullptr) ResourceManager::notifySysNullPtr< StateMachine >();

				statemachine->setDebounceMan(extctrl_debounceman);
				statemachine->setTaskMan(i2s_taskman_nortos);




		#endif


		#ifdef USE_FREERTOS


		 res = HAL_I2SEx_TransmitReceive_DMA (	&hi2s2,
										i2s_taskman->getDspManager()->txBufBlock.data(),
										i2s_taskman->getDspManager()->rxBufBlock.data(),
										AbstractFx::STEREO_SINGLE_BLK_SIZE_U16);
		#else

		// enable full duplex I2S
		if(i2s_taskman_nortos == nullptr) ResourceManager::notifySysNullPtr< I2STskManNoRTOS >();


		dspman->bringUp();
		i2s_taskman_nortos->getDspManager()->enable();


		#endif



		#ifdef USE_FREERTOS
				// start the RTOS
				vTaskStartScheduler();
		#endif

		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Total heap bytes used: " << ResourceManager::getUsedMem() << std::endl;

		while(1)
		{
			// loop these functions, check for updates to the system
			if(i2s_taskman_nortos == nullptr) ResourceManager::notifySysNullPtr< I2STskManNoRTOS >();
			i2s_taskman_nortos->nonRtosStateTask();
			if(i2s_taskman_nortos == nullptr) ResourceManager::notifySysNullPtr< I2STskManNoRTOS >();
			i2s_taskman_nortos->nonRtosDspTask();

		}
	}


	#ifdef USE_FREERTOS


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
						iirfx->process_half_u16_block(	&_i2s_taskman->getDspManager()->rxBufBlock,
													&_i2s_taskman->getDspManager()->txBufBlock);
	/*					for(size_t i = 0; i < i2s_taskman->getDspManager()->rxBufBlock.size(); i+=4)
						{
							int lSample = (int) (i2s_taskman->getDspManager()->rxBufBlock[i+0]<<16)|i2s_taskman->getDspManager()->rxBufBlock[i+1];
							int rSample = (int) (i2s_taskman->getDspManager()->rxBufBlock[i+2]<<16)|i2s_taskman->getDspManager()->rxBufBlock[i+3];

							float sum = (float) (lSample + rSample);
							sum = (1.0f - wet ) * sum + wet * reverbfx->processSample(sum);

							lSample = (int) sum;
							rSample = lSample;

							//restore to buffer
							i2s_taskman->getDspManager()->txBufBlock[i+0] = (lSample>>16)&0xFFFF;
							i2s_taskman->getDspManager()->txBufBlock[i+1] = lSample&0xFFFF;
							i2s_taskman->getDspManager()->txBufBlock[i+2] = (rSample>>16)&0xFFFF;
							i2s_taskman->getDspManager()->txBufBlock[i+3] = rSample&0xFFFF;
						}
	*/

						LEDA_G_GPIO_Port->ODR ^= GPIO_ODR_OD1_Msk;
					}
					if(item == 2)
					{
							iirfx->process_full_u16_block(	&_i2s_taskman->getDspManager()->rxBufBlock,
													&_i2s_taskman->getDspManager()->txBufBlock);
	/*					for(size_t i = 0; i < i2s_taskman->getDspManager()->rxBufBlock.size(); i+=4)
						{
							int lSample = (int) (_i2s_taskman->getDspManager()->rxBufBlock[i+4]<<16)|_i2s_taskman->getDspManager()->rxBufBlock[i+5];
							int rSample = (int) (_i2s_taskman->getDspManager()->rxBufBlock[i+6]<<16)|_i2s_taskman->getDspManager()->rxBufBlock[i+7];

							float sum = (float) (lSample + rSample);
							sum = (1.0f - wet) * sum + wet * reverbfx->processSample(sum);
							lSample = (int) sum;
							rSample = lSample;

							//restore to buffer
							_i2s_taskman->getDspManager()->txBufBlock[i+4] = (lSample>>16)&0xFFFF;
							_i2s_taskman->getDspManager()->txBufBlock[i+5] = lSample&0xFFFF;
							_i2s_taskman->getDspManager()->txBufBlock[i+6] = (rSample>>16)&0xFFFF;
							_i2s_taskman->getDspManager()->txBufBlock[i+7] = rSample&0xFFFF;
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

	#endif


#ifdef __cplusplus
	}
#endif

