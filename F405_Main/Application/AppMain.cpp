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
#include <ExtCtrlTaskManager.hpp>
#include <I2STaskManager.hpp>

#ifdef __cplusplus
	extern "C"
	{
#endif



	#define BLOCK_SIZE_U16 2048
	uint16_t rxBuf[BLOCK_SIZE_U16*2];
	uint16_t txBuf[BLOCK_SIZE_U16*2];
	uint8_t callback_state = 0;

	ExtCtrlTaskManager *extctrl_taskman = NULL;
	I2STaskManager *i2s_taskman = NULL;

	void appmain()
	{
		std::cout << "hello\n";

		setupPeriphInterrupts();

		run_sys_checks();
		// switch relay to enable the FX signal path
		HAL_GPIO_WritePin(RelayCoil_OUT_GPIO_Port, RelayCoil_OUT_Pin, GPIO_PIN_SET);

		// setup the external control task manager
		extctrl_taskman = new ExtCtrlTaskManager();
		extctrl_taskman->initEventMachine();
		extctrl_taskman->initTask();
		extctrl_taskman->initQueue();

		// start the I2S task manager
		i2s_taskman = new I2STaskManager();
		i2s_taskman->initTask();
		i2s_taskman->initQueue();

		// start FullDuplex I2S DMA
		HAL_I2SEx_TransmitReceive_DMA (&hi2s2, txBuf, rxBuf, BLOCK_SIZE_U16);

		// start the RTOS
		vTaskStartScheduler();

		while(1)
		{
			// not reached!
		}
	}


	/*
	 *
	 * STM32 Interrupt Handlers
	 *
	 */
/*	void HAL_I2SEx_TxRxHalfCpltCallback(I2S_HandleTypeDef *hi2s){

		i2s_taskman->queueSendFromISR_wrapper(1);

	}

	void HAL_I2SEx_TxRxCpltCallback(I2S_HandleTypeDef *hi2s){

		i2s_taskman->queueSendFromISR_wrapper(2);

	}
	void EXTI0_IRQHandler(void)
	{

		// clear the EXTI pending bit
		EXTI->PR &= ~((EXTI_PR_PR0_Pos));
	}

	void EXTI1_IRQHandler(void)
	{

		// clear the EXTI pending bit
		EXTI->PR &= ~((EXTI_PR_PR1_Pos));
	}

	void EXTI2_IRQHandler(void)
	{

		// clear the EXTI pending bit
		EXTI->PR &= ~((EXTI_PR_PR2_Pos));
	}

	void EXTI15_10_IRQHandler(void)
	{
		// send EXTI message to task manager
		if((EXTI->PR & EXTI_PR_PR13_Msk) == EXTI_PR_PR13_Msk)
		{
			isr_taskman->ISRQueueSendFromISR_wrapper(EXTI_PR_PR13);
		}
		if((EXTI->PR & EXTI_PR_PR14_Msk) == EXTI_PR_PR14_Msk)
		{
			isr_taskman->ISRQueueSendFromISR_wrapper(EXTI_PR_PR14);
		}

		// clear the EXTI pending bit
		EXTI->PR &= ~((EXTI_PR_PR13_Pos));
		EXTI->PR &= ~((EXTI_PR_PR14_Pos));
	}


	//
	void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
	{

	}


	void DMA1_Stream3_IRQHandler(void)
	{

		HAL_DMA_IRQHandler(&hdma_i2s2_ext_rx);

	}

	void DMA1_Stream4_IRQHandler(void)
	{

	  HAL_DMA_IRQHandler(&hdma_spi2_tx);

	}

*/

#ifdef __cplusplus
	}
#endif

