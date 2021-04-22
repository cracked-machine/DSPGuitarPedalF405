/*
 * FxDisabledState.cpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#include <FxDisabledState.hpp>

#include <StateMachine.hpp>
#include <DSPManager.hpp>

// STL
#include <iostream>

// HAL
#include <tim.h>
#include <i2s.h>
class DSPManager;

// FxDisabledState class

void FxDisabledState::evFootswitchA(StateMachine *machine)
{
	if(machine == nullptr)
		error_handler();

	setState(machine, machine->theStateList[StateMachine::FX_ENABLED]);

	#ifdef USE_HAL_DRIVER
		HAL_GPIO_WritePin(LEDA_G_GPIO_Port, LEDA_G_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LEDB_B_GPIO_Port, LEDB_B_Pin, GPIO_PIN_SET);

		// mute DSPManager
		//DSPManager::mute();


		// activate a oneshot timer to unmute after a 2ms period
		//HAL_TIM_Base_Start_IT(&htim11);

		HAL_I2S_DMAPause(&hi2s2);
		//HAL_GPIO_TogglePin(RelayCoil_OUT_GPIO_Port, RelayCoil_OUT_Pin);
		HAL_GPIO_WritePin(RelayCoil_OUT_GPIO_Port, RelayCoil_OUT_Pin, GPIO_PIN_SET);
		HAL_I2S_DMAResume(&hi2s2);


	#endif

	//std::cout << "FxDisabledState::evFootswitchA" << std::endl;
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


