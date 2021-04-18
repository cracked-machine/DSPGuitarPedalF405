/*
 * FxEnabledState.cpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#include "FxEnabledState.hpp"

#include <iostream>
#include "StateMachine.hpp"


// FxEnabledState class
void FxEnabledState::evFootswitchA(StateMachine *machine)
{
	setState(machine, machine->theStateList[StateMachine::FX_DISABLED]);

	#ifdef USE_HAL_DRIVER
		HAL_GPIO_WritePin(LEDA_R_GPIO_Port, LEDA_R_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDB_R_GPIO_Port, LEDB_R_Pin, GPIO_PIN_RESET);

		// toggle relay for clean/FX signal path
		HAL_GPIO_TogglePin(RelayCoil_OUT_GPIO_Port, RelayCoil_OUT_Pin);
	#endif

	std::cout << "FxEnabledState::evFootswitchA" << std::endl;
}

void FxEnabledState::evFootswitchB(StateMachine *machine)
{

}

void FxEnabledState::evUserSwitchA(StateMachine *machine)
{

}
void FxEnabledState::evUserSwitchB(StateMachine *machine)
{

}
void FxEnabledState::evRotaryEncoderA(StateMachine *machine)
{

}
void FxEnabledState::evRotaryEncoderB(StateMachine *machine)
{

}

