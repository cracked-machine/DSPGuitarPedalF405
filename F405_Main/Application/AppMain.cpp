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

// system tests
#include <pedal_io_test.hpp>

#include "PeriphInterrupts.hpp"

#include <EventMachine.hpp>

#include <AbstractTaskManager.hpp>

#ifdef __cplusplus
	extern "C"
	{
#endif


	#define BLOCK_SIZE_U16 2048
	uint16_t rxBuf[BLOCK_SIZE_U16*2];
	uint16_t txBuf[BLOCK_SIZE_U16*2];
	uint8_t callback_state = 0;

	//ExtCtrlTaskManager *extctrl_taskman = NULL;
	//I2STaskManager *i2s_taskman = NULL;

	I2STaskManager_t *i2s_taskman;
	void I2STaskCode( void * parm );
	static StaticQueue_t I2S_StaticQueue;

	ExtCtrlTaskManager_t *extctrl_taskman;
	void ExtCtrlTaskCode( void * parm );
	static StaticQueue_t ExtCtrl_StaticQueue;


	void appmain()
	{

		std::cout << "hello\n";

		setupPeriphInterrupts();

		//run_sys_checks();

		//HAL_EnableCompensationCell();

		i2s_taskman = new I2STaskManager_t(200, 1);
		AbstractTaskPtr_t taskptr = &I2STaskCode;
		i2s_taskman->initTask("I2STaskManager", taskptr);
		i2s_taskman->initQueue(&I2S_StaticQueue);

		extctrl_taskman = new ExtCtrlTaskManager_t(200, 1);
		AbstractTaskPtr_t taskptr2 = &ExtCtrlTaskCode;
		extctrl_taskman->initStateMachine();
		extctrl_taskman->initTask("ExtCtrlTaskManager", taskptr2);
		extctrl_taskman->initQueue(&ExtCtrl_StaticQueue);

		// start FullDuplex I2S DMA
		HAL_I2SEx_TransmitReceive_DMA (&hi2s2, txBuf, rxBuf, BLOCK_SIZE_U16);

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
					//HAL_GPIO_TogglePin(LEDA_G_GPIO_Port, LEDA_G_Pin);
					LEDA_G_GPIO_Port->ODR ^= GPIO_ODR_OD1_Msk;
				}
				if(item == 2)
				{
					//HAL_GPIO_TogglePin(LEDB_G_GPIO_Port, LEDB_G_Pin);
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

#ifdef __cplusplus
	}
#endif
