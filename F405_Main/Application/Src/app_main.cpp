/*
 * AppMain.cpp
 *
 *  Created on: Apr 11, 2021
 *      Author: chris
 */

#include <app_main.hpp>

#include <pedal_io_test.hpp>

#include <arm_math.h>

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include "tim.h"



// SEGGER JLink RTT write redirect
#include <SEGGER_RTT.h>

// C++ STL
#include <iostream>

#ifdef __cplusplus
	extern "C"
	{
#endif

	void appmain()
	{
		std::cout << "hello\n";

		// enable the rotary encoders
		HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);
		HAL_TIM_Encoder_Start_IT(&htim4, TIM_CHANNEL_ALL);

		run_sys_checks();

		while(1)
		{

		}
	}

#ifdef __cplusplus
	}
#endif

