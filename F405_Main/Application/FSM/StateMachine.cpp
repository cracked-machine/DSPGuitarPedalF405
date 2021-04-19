/*
 * StateMachine.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */

#include "StateMachine.hpp"
#include "AbstractState.hpp"


// The system state machine
StateMachine::StateMachine()
{
	// set the default system state to fx bypass
	state = theStateList[StateMachine::FX_DISABLED];

}

// only used by CppUTest
StateMachine::~StateMachine()
{
	for (auto &item : theStateList)
		delete item;

}

AbstractState * StateMachine::getState()
{
	return state;
}

void StateMachine::setDebounceMan(DebounceManager *pDebounceMan)
{
	theDebounceMan = nullptr;
	if(pDebounceMan == nullptr)
	{
		error_handler();
	}
	else
	{
		theDebounceMan = pDebounceMan;
		// start the debounce timer
		theDebounceMan->start();
	}
}

DebounceManager* StateMachine::getDebounceMan()
{
	return theDebounceMan;
}

void StateMachine::evFootswitchA()
{
	if(theDebounceMan->check_debounce())
		state->evFootswitchA(this);
}

void StateMachine::evFootswitchB()
{
	if(theDebounceMan->check_debounce())
		state->evFootswitchB(this);
}

void StateMachine::evUserSwitchA()
{
	if(theDebounceMan->check_debounce())
		state->evUserSwitchA(this);
}

void StateMachine::evUserSwitchB()
{
	if(theDebounceMan->check_debounce())
		state->evUserSwitchB(this);
}

void StateMachine::evRotaryEncoderA()
{
	if(theDebounceMan->check_debounce())
		state->evRotaryEncoderA(this);
}

void StateMachine::evRotaryEncoderB()
{
	if(theDebounceMan->check_debounce())
		state->evRotaryEncoderB(this);
}


void StateMachine::error_handler()
{
	std::cout << "Caught error at StateMachine::error_handle()" << std::endl;
	while(FOREVER)
	{
		// wait here on target
	}
}



