/*
 * AppMain.cpp
 *
 *  Created on: Apr 11, 2021
 *      Author: chris
 */

#include <app_main.hpp>

// HAL
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include "tim.h"

// STL
#include <iostream>

// system tests
#include <pedal_io_test.hpp>

// rtos task manager
//#include <FreeRTOS_UserTasks.hpp>

#include <EventMachine.hpp>
#include <ISRTaskManager.hpp>

#ifdef __cplusplus
	extern "C"
	{
#endif

	ISRTaskManager *taskman = NULL;


	void appmain()
	{
		std::cout << "hello\n";

		// EXTI init
		HAL_NVIC_SetPriority(EXTI0_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI0_IRQn);
		HAL_NVIC_SetPriority(EXTI1_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI1_IRQn);
		HAL_NVIC_SetPriority(EXTI2_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI2_IRQn);
		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

		// enable the rotary encoders
		HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);
		HAL_TIM_Encoder_Start_IT(&htim4, TIM_CHANNEL_ALL);

		run_sys_checks();

		taskman = new ISRTaskManager();
		taskman->initEventMachine();
		taskman->initIsrTask();
		taskman->initIsrQueue();

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
			taskman->ISRQueueSendFromISR_wrapper(EXTI_PR_PR13);
		}
		if((EXTI->PR & EXTI_PR_PR14_Msk) == EXTI_PR_PR14_Msk)
		{
			taskman->ISRQueueSendFromISR_wrapper(EXTI_PR_PR14);
		}

		// clear the EXTI pending bit
		EXTI->PR &= ~((EXTI_PR_PR13_Pos));
		EXTI->PR &= ~((EXTI_PR_PR14_Pos));
	}


	//
	void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
	{

	}

#ifdef __cplusplus
	}
#endif

