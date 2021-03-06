/*
 * pedal_io_test.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */

#include "gpio.h"
#include "stm32f4xx_hal.h"


#ifdef __cplusplus
	extern "C"
	{
#endif

	void test_leds(size_t iterations);
	void test_relay(size_t iterations);
/*
#define LEDA_R_Pin GPIO_PIN_0
#define LEDA_R_GPIO_Port GPIOB
#define LEDA_G_Pin GPIO_PIN_1
#define LEDA_G_GPIO_Port GPIOB
#define LEDA_B_Pin GPIO_PIN_2
#define LEDA_B_GPIO_Port GPIOB
#define LEDB_R_Pin GPIO_PIN_10
#define LEDB_R_GPIO_Port GPIOA
#define LEDB_G_Pin GPIO_PIN_11
#define LEDB_G_GPIO_Port GPIOA
#define LEDB_B_Pin GPIO_PIN_12
#define LEDB_B_GPIO_Port GPIOA

#define RelayCoil_OUT_Pin GPIO_PIN_0
#define RelayCoil_OUT_GPIO_Port GPIOC
*/

	void run_sys_checks()
	{
		test_leds(1);
		test_relay(1);
	}

	void test_relay(size_t iterations)
	{
		for(size_t i = 0 ; i < iterations; i++)
		{
			HAL_GPIO_TogglePin(RelayCoil_OUT_GPIO_Port, RelayCoil_OUT_Pin);
			HAL_Delay(1000);
			HAL_GPIO_TogglePin(RelayCoil_OUT_GPIO_Port, RelayCoil_OUT_Pin);
			HAL_Delay(1000);
		}

	}

	void test_leds(size_t iterations)
	{
		for(size_t i = 0 ; i < iterations; i++)
		{
			// turn on/off red leds
			HAL_GPIO_TogglePin(LEDA_R_GPIO_Port, LEDA_R_Pin);
			HAL_GPIO_TogglePin(LEDB_R_GPIO_Port, LEDB_R_Pin);
			HAL_Delay(1000);
			HAL_GPIO_TogglePin(LEDA_R_GPIO_Port, LEDA_R_Pin);
			HAL_GPIO_TogglePin(LEDB_R_GPIO_Port, LEDB_R_Pin);

			// turn on/off green leds
			HAL_GPIO_TogglePin(LEDA_R_GPIO_Port, LEDA_G_Pin);
			HAL_GPIO_TogglePin(LEDB_R_GPIO_Port, LEDB_G_Pin);
			HAL_Delay(1000);
			HAL_GPIO_TogglePin(LEDA_R_GPIO_Port, LEDA_G_Pin);
			HAL_GPIO_TogglePin(LEDB_R_GPIO_Port, LEDB_G_Pin);

			// turn on/off blue leds
			HAL_GPIO_TogglePin(LEDA_R_GPIO_Port, LEDA_B_Pin);
			HAL_GPIO_TogglePin(LEDB_R_GPIO_Port, LEDB_B_Pin);
			HAL_Delay(1000);
			HAL_GPIO_TogglePin(LEDA_R_GPIO_Port, LEDA_B_Pin);
			HAL_GPIO_TogglePin(LEDB_R_GPIO_Port, LEDB_B_Pin);
		}
	}


#ifdef __cplusplus
	}
#endif
