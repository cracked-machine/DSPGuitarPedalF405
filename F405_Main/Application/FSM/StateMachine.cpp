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
	state = NULL;
	state = theStateList[StateMachine::FX_DISABLED];

	// start the debounce timer
	debounceTim14.start();
}


AbstractState * StateMachine::getState()
{
	return state;
}


void StateMachine::evFootswitchA()
{
	if(debounceTim14.check_debounce())
		state->evFootswitchA(this);
}

void StateMachine::evFootswitchB()
{
	if(debounceTim14.check_debounce())
		state->evFootswitchB(this);
}

void StateMachine::evUserSwitchA()
{
	if(debounceTim14.check_debounce())
		state->evUserSwitchA(this);
}

void StateMachine::evUserSwitchB()
{
	if(debounceTim14.check_debounce())
		state->evUserSwitchB(this);
}

void StateMachine::evRotaryEncoderA()
{
	if(debounceTim14.check_debounce())
		state->evRotaryEncoderA(this);
}

void StateMachine::evRotaryEncoderB()
{
	if(debounceTim14.check_debounce())
		state->evRotaryEncoderB(this);
}




