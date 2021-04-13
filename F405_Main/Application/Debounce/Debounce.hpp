/*
 * Debounce.hpp
 *
 *  Created on: Apr 13, 2021
 *      Author: chris
 */

#ifndef DEBOUNCE_DEBOUNCE_HPP_
#define DEBOUNCE_DEBOUNCE_HPP_

#include "stm32f4xx_hal.h"

template <class T>
class DebounceManager
{

public:

	DebounceManager(T* _tim, size_t _delay)
	{
		theTimer = _tim;
		delay = _delay;
		last_interrupt_time = 0;
		interrupt_time = 0;


	}

	void start();
	bool check_debounce();

private:

	T* theTimer;
	size_t delay;
	size_t interrupt_time;
	size_t last_interrupt_time;

};


template <class T>
void DebounceManager<T>::start()
{
	theTimer->CR1 |= TIM_CR1_CEN_Msk;
}

template <class T>
bool DebounceManager<T>::check_debounce()
{
	bool res = false;

	interrupt_time = theTimer->CNT;
	if ((interrupt_time - last_interrupt_time) > delay)
	{
		res = true;
	}

	last_interrupt_time = interrupt_time;
	return res;
}


typedef DebounceManager<TIM_TypeDef> HALDebounceManager;

#endif /* DEBOUNCE_DEBOUNCE_HPP_ */
