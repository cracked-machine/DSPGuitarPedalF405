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

#include <Debounce.hpp>
#include "FxDisabledState.hpp"
#include "FxEnabledState.hpp"


#include <array>

#ifndef USE_HAL_DRIVER
	#include <test_hal_testenv.h>
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

	static const size_t MAX_NUM_STATE = 2;

	// create all system states at startup, they are not deleted.
	std::array<AbstractState*, MAX_NUM_STATE> theStateList = {
		new FxDisabledState(),
		new FxEnabledState()
	};



	enum states_enum
	{
		FX_DISABLED,
		FX_ENABLED
	};

	AbstractState* getState();
	void setDebounceMan(DebounceManager *pDebounceMan);
private:

	// the current system state
	AbstractState* state;

	// manage the debounce for all system events
	//DebounceManager debounceTim14  = {DebounceManager(TIM14, 800)};
	DebounceManager *theDebounceMan;
};

#endif // INC_STATEMACHINE_HPP_ */
