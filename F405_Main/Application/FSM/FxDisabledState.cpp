/*
 * FxDisabledState.cpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#include "FxDisabledState.hpp"


// FxDisabledState class
void FxDisabledState::evFootswitchA(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_ENABLED]);
}
void FxDisabledState::evFootswitchB(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_DISABLED]);
}

void FxDisabledState::evUserSwitchA(EventMachine *machine)
{

}
void FxDisabledState::evUserSwitchB(EventMachine *machine)
{

}
void FxDisabledState::evRotaryEncoderA(EventMachine *machine)
{

}
void FxDisabledState::evRotaryEncoderB(EventMachine *machine)
{

}
