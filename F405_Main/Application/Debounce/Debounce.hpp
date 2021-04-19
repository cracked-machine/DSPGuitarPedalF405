/*
 * Debounce.hpp
 *
 *  Created on: Apr 13, 2021
 *      Author: chris
 */

#ifndef DEBOUNCE_DEBOUNCE_HPP_
#define DEBOUNCE_DEBOUNCE_HPP_

#include <assert.h>
#ifdef USE_HAL_DRIVER
	#include "stm32f4xx_hal.h"
#else
	#include <test_hal_testenv.h>
#endif

#ifndef DISABLE_ERROR_HANDLER
#define FOREVER 1
#else
#define FOREVER 0
#endif

class DebounceManager
{

public:

	DebounceManager(TIM_TypeDef*  _tim, size_t _delay);

	void start();
	bool check_debounce();
	void error_handler();

	bool isStarted();

private:

	TIM_TypeDef*  theTimer;
	size_t delay;
	size_t interrupt_time;
	size_t last_interrupt_time;

};


#endif /* DEBOUNCE_DEBOUNCE_HPP_ */


