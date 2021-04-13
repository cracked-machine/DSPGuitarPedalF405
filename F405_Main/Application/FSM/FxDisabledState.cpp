/*
 * FxDisabledState.cpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#include "FxDisabledState.hpp"
#include <iostream>

// FxDisabledState class

void FxDisabledState::evFootswitchA(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_ENABLED]);
#ifdef USE_HAL_DRIVER
	HAL_GPIO_WritePin(LEDA_R_GPIO_Port, LEDA_R_Pin, GPIO_PIN_SET);
#endif
	std::cout << "FxDisabledState::evFootswitchA" << std::endl;
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