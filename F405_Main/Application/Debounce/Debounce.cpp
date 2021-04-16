/*
 * Debounce.cpp
 *
 *  Created on: Apr 14, 2021
 *      Author: chris
 */

#include "Debounce.hpp"
#include <iostream>


void DebounceManager::start()
{
	theTimer->CR1 |= TIM_CR1_CEN_Msk;
}


bool DebounceManager::check_debounce()
{
	bool res = false;

	interrupt_time = theTimer->CNT;
	std::cout << "time:" << interrupt_time << " - last:" << last_interrupt_time << std::endl;
	if ((interrupt_time - last_interrupt_time) > delay)
	{
		res = true;
	}

	last_interrupt_time = interrupt_time;
	return res;
}
