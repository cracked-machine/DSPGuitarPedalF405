/*
 * FxEnabledState.cpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#include <FxEnabledState.hpp>
#include <StateMachine.hpp>
#include <DSPManager.hpp>

// STL
#include <iostream>

// HAL
#ifndef ENABLE_CPPUTEST
#include <i2s.h>
#endif

// FxEnabledState class
void FxEnabledState::evFootswitchA(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
	setState(machine, machine->theStateList[StateMachine::FX_DISABLED]);

	#ifdef USE_HAL_DRIVER
		HAL_GPIO_WritePin(LEDA_G_GPIO_Port, LEDA_G_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDB_G_GPIO_Port, LEDB_G_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEDB_B_GPIO_Port, LEDB_B_Pin, GPIO_PIN_RESET);


		//HAL_I2S_DMAPause(&hi2s2);
		HAL_GPIO_WritePin(RelayCoil_OUT_GPIO_Port, RelayCoil_OUT_Pin, GPIO_PIN_RESET);
		//HAL_I2S_DMAResume(&hi2s2);


	#endif

	//std::cout << "FxEnabledState::evFootswitchA" << std::endl;
}

void FxEnabledState::evFootswitchB(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
}

void FxEnabledState::evUserSwitchA(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
}
void FxEnabledState::evUserSwitchB(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
}
void FxEnabledState::evRotaryEncoderA(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
}
void FxEnabledState::evRotaryEncoderB(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	// do state behavior here:
}

