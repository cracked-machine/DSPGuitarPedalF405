/*
 * PeriphInterrupts.cpp
 *
 *  Created on: Apr 16, 2021
 *      Author: chris
 */



#include "PeriphInterrupts.hpp"

// HAL
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include "tim.h"
#include "stm32f4xx_hal_i2s.h"
#include "i2s.h"



#include <AppMain.hpp>
#include <ExtCtrlTaskManager.hpp>
#include <I2STaskManager.hpp>

#ifdef __cplusplus
	extern "C"
	{
#endif

	// defined in Core/Src/i2s.c
	extern DMA_HandleTypeDef hdma_i2s2_ext_rx;
	extern DMA_HandleTypeDef hdma_spi2_tx;

	// defined in Application/AppMain.cpp
	extern ExtCtrlTaskManager *extctrl_taskman;
	extern I2STaskManager *i2s_taskman;


	void setupPeriphInterrupts()
	{
		// Setup EXTI IRQ
		HAL_NVIC_SetPriority(EXTI0_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI0_IRQn);
		HAL_NVIC_SetPriority(EXTI1_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI1_IRQn);
		HAL_NVIC_SetPriority(EXTI2_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI2_IRQn);
		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

		// Setup DMA1_Stream3_IRQn for I2S receive
		HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);

		// Setup DMA1_Stream4_IRQn for I2S transmit
		HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);

		// enable the rotary encoders
		HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);
		HAL_TIM_Encoder_Start_IT(&htim4, TIM_CHANNEL_ALL);
	}


	void HAL_I2SEx_TxRxHalfCpltCallback(I2S_HandleTypeDef *hi2s){

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
			extctrl_taskman->ExtCtrlQueueSendFromISR_wrapper(EXTI_PR_PR13);
		}
		if((EXTI->PR & EXTI_PR_PR14_Msk) == EXTI_PR_PR14_Msk)
		{
			extctrl_taskman->ExtCtrlQueueSendFromISR_wrapper(EXTI_PR_PR14);
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

#ifdef __cplusplus
	}
#endif
