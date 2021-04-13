/*
 * FxEnabledState.cpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#include "FxEnabledState.hpp"

#include <iostream>



// FxEnabledState class
void FxEnabledState::evFootswitchA(EventMachine *machine)
{
	setState(machine, machine->states_list[EventMachine::FX_DISABLED]);
#ifdef USE_HAL_DRIVER
	HAL_GPIO_WritePin(LEDA_R_GPIO_Port, LEDA_R_Pin, GPIO_PIN_RESET);
#endif
	std::cout << "FxEnabledState::evFootswitchA" << std::endl;
}

void FxEnabledState::evFootswitchB(EventMachine *machine)
{
	//setState(machine, machine->states_list[EventMachine::FX_DISABLED]);
	AbstractState::evFootswitchB(machine);
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

