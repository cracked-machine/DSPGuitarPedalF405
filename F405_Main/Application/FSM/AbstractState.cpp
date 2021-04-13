/*
 * AbstractState.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */


#include <AbstractState.hpp>


// AbstractState class
AbstractState::~AbstractState() {}


void AbstractState::evFootswitchA(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_DISABLED]);
}

void AbstractState::evFootswitchB(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_DISABLED]);
}

void AbstractState::evUserSwitchA(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_DISABLED]);
}

void AbstractState::evUserSwitchB(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_DISABLED]);
}

void AbstractState::evRotaryEncoderA(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_DISABLED]);
}

void AbstractState::evRotaryEncoderB(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_DISABLED]);
}

void AbstractState::setState(EventMachine *machine, AbstractState *state)
{
  machine->state = state;
}





