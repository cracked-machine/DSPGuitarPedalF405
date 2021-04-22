/*
 * FxDisabledState.cpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#include <FxDisabledState.hpp>
#include <StateMachine.hpp>
#include <iostream>
#include <tim.h>
#include <DSPManager.hpp>
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
		DSPManager::mute();

		// activate a oneshot timer to unmute after a 2ms period
		HAL_TIM_Base_Start_IT(&htim11);


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


