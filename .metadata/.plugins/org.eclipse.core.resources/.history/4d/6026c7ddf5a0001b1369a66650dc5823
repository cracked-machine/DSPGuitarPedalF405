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



class DebounceManager
{

public:

	DebounceManager(TIM_TypeDef*  _tim, size_t _delay)
	{
		// input conditioning checks
		assert(_tim != NULL);

		if(_delay < 0 || _delay > 65535)
			_delay = 65535;

		// init members
		theTimer = _tim;
		delay = _delay;
		last_interrupt_time = 0;
		interrupt_time = 0;

		// set the timer counter to max resolution
		theTimer->PSC = 65535;
		theTimer->ARR = 65535;
	}



	void start();
	bool check_debounce();


private:

	TIM_TypeDef*  theTimer;
	size_t delay;
	size_t interrupt_time;
	size_t last_interrupt_time;

};








#endif /* DEBOUNCE_DEBOUNCE_HPP_ */


