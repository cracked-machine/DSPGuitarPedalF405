/*
 * FxEnabledState.cpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#include "FxEnabledState.hpp"


// FxEnabledState class
void FxEnabledState::evFootswitchA(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_ENABLED]);
}
void FxEnabledState::evFootswitchB(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_DISABLED]);
}

void FxEnabledState::evUserSwitchA(EventMachine *machine)
{

}
void FxEnabledState::evUserSwitchB(EventMachine *machine)
{

}
void FxEnabledState::evRotaryEncoderA(EventMachine *machine)
{

}
void FxEnabledState::evRotaryEncoderB(EventMachine *machine)
{

}
