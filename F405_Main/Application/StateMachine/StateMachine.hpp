/*
 * StateMachine.hpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */


#ifndef INC_STATEMACHINE_HPP_
#define INC_STATEMACHINE_HPP_

#pragma once

#include <AbstractState.hpp>
class AbstractState;

#include <I2STaskManager.hpp>
class I2STskManNoRTOS;


#include <Debounce.hpp>
#include <FxDisabledState.hpp>
#include <FxEnabledState.hpp>


#include <array>

#ifdef USE_HAL_DRIVER
	#include "stm32f4xx_hal.h"
	#include "main.h"
#else
	#include <test_hal_testenv.h>
#endif

#ifndef DISABLE_ERROR_HANDLER
	#define FOREVER 1
#else
	#define FOREVER 0
#endif



//#define MAX_NUM_STATE 2

class StateMachine
{

	friend class AbstractState;
public:
	StateMachine();
	~StateMachine();

	void evFootswitchA();
	void evFootswitchB();
	void evUserSwitchA();
	void evUserSwitchB();
	void evRotaryEncoderA();
	void evRotaryEncoderB();
	AbstractState* getState();
	void setDebounceMan(DebounceManager *pDebounceMan);



	DebounceManager* getDebounceMan();

	static const size_t MAX_NUM_STATE = 2;

	// create all system states at startup, they are not deleted.
	std::array<AbstractState*, MAX_NUM_STATE> theStateList = {
		new(std::nothrow)  FxDisabledState(),
		new(std::nothrow)  FxEnabledState()
	};


	enum states_enum
	{
		FX_DISABLED,
		FX_ENABLED
	};

	/*
	void error_handler();
	enum stateFatalErrTypes
	{
		STATUS_OK = 0,
		NULL_DEBOUNCE_PTR
	};

	StateMachine::stateFatalErrTypes getErrorStatus();
*/
	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< StateMachine >(size))
				return malloc(size);
			else
				return nullptr;
	}


	void setTaskMan(I2STskManNoRTOS *pTaskMan);
	I2STskManNoRTOS* getTaskMan();

private:

	// the current system state
	AbstractState* state;

	// manage the debounce for all system events
	DebounceManager *theDebounceMan;

	I2STskManNoRTOS *theTaskMan;

	//StateMachine::stateFatalErrTypes status = STATUS_OK;
	//void error_handler(StateMachine::stateFatalErrTypes pError);
};

#endif // INC_STATEMACHINE_HPP_ */
