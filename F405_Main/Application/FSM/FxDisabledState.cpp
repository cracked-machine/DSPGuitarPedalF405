/*
 * FxDisabledState.cpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#include "FxDisabledState.hpp"

#include "StateMachine.hpp"
#include <iostream>

// FxDisabledState class

void FxDisabledState::evFootswitchA(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	setState(machine, machine->theStateList[StateMachine::FX_ENABLED]);

	#ifdef USE_HAL_DRIVER
		HAL_GPIO_WritePin(LEDA_R_GPIO_Port, LEDA_R_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LEDB_R_GPIO_Port, LEDB_R_Pin, GPIO_PIN_SET);
		// toggle relay for clean/FX signal path
		HAL_GPIO_TogglePin(RelayCoil_OUT_GPIO_Port, RelayCoil_OUT_Pin);
	#endif

	std::cout << "FxDisabledState::evFootswitchA" << std::endl;
}

void FxDisabledState::evFootswitchB(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
}

void FxDisabledState::evUserSwitchA(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
}
void FxDisabledState::evUserSwitchB(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
}
void FxDisabledState::evRotaryEncoderA(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
}
void FxDisabledState::evRotaryEncoderB(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
}


