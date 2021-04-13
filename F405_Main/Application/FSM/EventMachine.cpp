/*
 * EventMachine.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */

#include "EventMachine.hpp"

#include "FxDisabledState.hpp"
#include "FxEnabledState.hpp"



EventMachine::EventMachine()
{
	// instantiate the state objects now at init for the duration
	states_list[EventMachine::FX_DISABLED] = new FxDisabledState();
	states_list[EventMachine::FX_ENABLED] = new FxEnabledState();

	state = states_list[EventMachine::FX_DISABLED];
}


EventMachine::~EventMachine()
{
	for(AbstractState* s : states_list)
		delete s;
}

AbstractState * EventMachine::getState()
{
	return state;
}

void EventMachine::evFootswitchA()
{
	state->evFootswitchA(this);
}

void EventMachine::evFootswitchB()
{
	state->evFootswitchB(this);
}

void EventMachine::evUserSwitchA()
{
	state->evUserSwitchA(this);
}

void EventMachine::evUserSwitchB()
{
	state->evUserSwitchB(this);
}

void EventMachine::evRotaryEncoderA()
{
	state->evRotaryEncoderA(this);
}

void EventMachine::evRotaryEncoderB()
{
	state->evRotaryEncoderB(this);
}



