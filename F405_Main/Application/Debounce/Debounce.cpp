/*
 * Debounce.cpp
 *
 *  Created on: Apr 14, 2021
 *      Author: chris
 */

#include "Debounce.hpp"
#include <iostream>


DebounceManager::DebounceManager(TIM_TypeDef*  pTim, size_t pDelay)
{
	theTimer = nullptr;

	// input conditioning checks
	if(!pTim)
	{
		error_handler(NULL_TIMER_ERR);
	}
	else
	{
		if(pDelay < 0 || pDelay > 65535)
			pDelay = 200;

		// init members
		theTimer = pTim;
		delay = pDelay;
		last_interrupt_time = 0;
		interrupt_time = 0;

		// set the timer counter to max resolution
		theTimer->PSC = 65535;
		theTimer->ARR = 65535;
	}
}

bool DebounceManager::isStarted()
{
	if(theTimer == nullptr)
	{
		error_handler(NULL_TIMER_ERR);
	}
	if((theTimer->CR1 & TIM_CR1_CEN_Msk) == TIM_CR1_CEN_Msk)
	{
		return true;
	}
	return false;
}

void DebounceManager::start()
{
	if(theTimer == nullptr)
	{
		error_handler(NULL_TIMER_ERR);
	}
	else
	{
		theTimer->CR1 |= TIM_CR1_CEN_Msk;
	}
}


bool DebounceManager::check_debounce()
{
	bool res = false;

	interrupt_time = theTimer->CNT;
	//std::cout << "CNT:" << interrupt_time << " - lastCNT:" << last_interrupt_time << " - diff:" << (interrupt_time - last_interrupt_time) << std::endl;
	if ((interrupt_time - last_interrupt_time) > delay)
	{
		res = true;
	}

	last_interrupt_time = interrupt_time;
	return res;
}

DebounceManager::FatalErrTypes DebounceManager::getErrorStatus()
{
	return status;
}

void DebounceManager::error_handler(DebounceManager::FatalErrTypes pError)
{
	std::cout << "Caught error(" << pError << ") at DebounceManager::error_handle()" << std::endl;
	status = pError;
	while(FOREVER)
	{
		// wait here on target
	}


}

