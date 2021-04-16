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
	debounceTim14 = new DebounceManager(TIM14, 800);
	debounceTim14->start();
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
	if(debounceTim14->check_debounce())
		state->evFootswitchA(this);
}

void EventMachine::evFootswitchB()
{
	if(debounceTim14->check_debounce())
		state->evFootswitchB(this);
}

void EventMachine::evUserSwitchA()
{
	if(debounceTim14->check_debounce())
		state->evUserSwitchA(this);
}

void EventMachine::evUserSwitchB()
{
	if(debounceTim14->check_debounce())
		state->evUserSwitchB(this);
}

void EventMachine::evRotaryEncoderA()
{
	if(debounceTim14->check_debounce())
		state->evRotaryEncoderA(this);
}

void EventMachine::evRotaryEncoderB()
{
	if(debounceTim14->check_debounce())
		state->evRotaryEncoderB(this);
}




