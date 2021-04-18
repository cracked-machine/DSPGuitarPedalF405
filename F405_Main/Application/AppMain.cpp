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


// STL
#include <iostream>
#include <array>
#include <assert.h>


#include <pedal_io_test.hpp>

#include "PeriphInterrupts.hpp"
#include <BaseTaskManager.hpp>
#include <StateMachine.hpp>
#include "DSPManager.hpp"

#ifdef USE_HAL_DRIVER
	// Disable all usage of delete operator
	void operator delete(void*)
	{
		return;
	}
#endif

#ifdef __cplusplus
	extern "C"
	{
#endif


	//uint16_t rxBuf[BLOCK_SIZE_U16*2];
	//uint16_t txBuf[BLOCK_SIZE_U16*2];
	std::array<uint16_t, STEREO_BLOCK_SIZE_U16> rxBuf{};
	std::array<uint16_t, STEREO_BLOCK_SIZE_U16> txBuf{};


	uint8_t callback_state = 0;

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

	DSPManager *dspman;
	IIRFilterFx *iirfx;


	void appmain()
	{

		std::cout << "hello\n";

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

		// External Control task instantiation on the heap at startup
		//
		extctrl_taskman = new ExtCtrlTaskManager_t(200, 1);

		// Set the statemachine
		extctrlMachine = new StateMachine();
		// set the delay for the external control debounce
		extctrl_debounceman = new DebounceManager(TIM14, 200);
		extctrlMachine->setDebounceMan(extctrl_debounceman);
		extctrl_taskman->setStateMachine(extctrlMachine);


		// Set the STATIC freeertos task to global function pointer "ExtCtrlTaskCode()"
		AbstractTaskPtr_t ExtCtrlTaskPtr = &ExtCtrlTaskCode;
		extctrl_taskman->setTask("ExtCtrlTaskManager", ExtCtrlTaskPtr);

		// Set the STATIC freertos queue
		extctrl_taskman->setQueue(&ExtCtrl_StaticQueue);
		//

		iirfx = new IIRFilterFx();
		dspman = new DSPManager(iirfx);

		// start FullDuplex I2S DMA
		HAL_I2SEx_TransmitReceive_DMA (&hi2s2, txBuf.data(), rxBuf.data(), BLOCK_SIZE_U16);
		//HAL_I2SEx_TransmitReceive_DMA (&hi2s2, txBuf, rxBuf, BLOCK_SIZE_U16);

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
		I2STaskManager_t *i2s_taskman = static_cast<I2STaskManager_t*>(parm);



		while(1)
		{
			uint8_t item = 0;
			//std::cout << "I2STaskCode retrieved queue item" << item << std::endl;
			if( ISRQueueReceive( i2s_taskman->getQueue(), &( item ), ( TickType_t ) 0 ) == pdPASS)
			{
				if(item == 1)
				{
					iirfx->process_half_u16(&rxBuf, &txBuf);
//					for(size_t i = 0; i < BLOCK_SIZE_U16; i++ )
//						txBuf[i] = rxBuf[i];
					LEDA_G_GPIO_Port->ODR ^= GPIO_ODR_OD1_Msk;
				}
				if(item == 2)
				{
					iirfx->process_full_u16(&rxBuf, &txBuf);
//					for(size_t i = BLOCK_SIZE_U16; i < STEREO_BLOCK_SIZE_U16; i++ )
//						txBuf[i] = rxBuf[i];
					LEDB_G_GPIO_Port->ODR ^= GPIO_ODR_OD11_Msk;
				}

			}
		}
	}

	/* Function that implements the task being created. */
	void ExtCtrlTaskCode( void * parm )
	{
		ExtCtrlTaskManager_t *extctrl_taskman = static_cast<ExtCtrlTaskManager_t*>(parm);
		while(1)
		{
			uint16_t item = 0;
			std::cout << "ExtCtrlTaskCode waiting for queue item" << std::endl;

			if( ISRQueueReceive( extctrl_taskman->getQueue(), &( item ), ( TickType_t ) 10 ) == pdPASS)
			{
				std::cout << "ExtCtrlTaskCode retrieved queue item" << std::endl;
				switch(item)
				{
					case EXTI_PR_PR13:

						extctrl_taskman->getStateMachine()->evFootswitchA();
						break;
					case EXTI_PR_PR14:
						extctrl_taskman->getStateMachine()->evFootswitchB();
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

