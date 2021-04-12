/*
 * AppMain.cpp
 *
 *  Created on: Apr 11, 2021
 *      Author: chris
 */

#include <app_main.hpp>

#include <pedal_io_test.hpp>
#include <arm_math.h>

//#include <EventMachine_old.hpp>
#include <EventMachine.hpp>

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include "tim.h"

#include <SEGGER_RTT.h>

// C++ STL
#include <iostream>

#ifdef __cplusplus
	extern "C"
	{
#endif


	EventMachine em;

	void appmain()
	{
		std::cout << "hello\n";



		// enable the rotary encoders
		HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);
		HAL_TIM_Encoder_Start_IT(&htim4, TIM_CHANNEL_ALL);

		run_sys_checks();

		while(1)
		{
			//em.processEvent();
		}
	}

	// callback for switches
	void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
	{
		//em.setNewEvent( (EventMachine::Event)GPIO_Pin );
		switch(GPIO_Pin)
		{
			case GPIO_PIN_13:
				em.evFootswitchA();
				break;
			case GPIO_PIN_14:
				em.evFootswitchB();
				break;
		}

	}

	//
	void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
	{

	}

#ifdef __cplusplus
	}
#endif

