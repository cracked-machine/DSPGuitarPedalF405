/*
 * StateMachine.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */

#include <AbstractState.hpp>
#include <StateMachine.hpp>


// The system state machine
StateMachine::StateMachine()
{
	// set the default system state to fx bypass
	state = theStateList[StateMachine::FX_DISABLED];

}

// only used by CppUTest
StateMachine::~StateMachine()
{
	for (auto &item : theStateList)
		delete item;

}

AbstractState * StateMachine::getState()
{
	if(this->state == nullptr)
	{
		ResourceManager::notifySysNullPtr< StateMachine >();
		return nullptr; // not reached, prevents warning
	}
	else
	{
		return state;
	}

}

void StateMachine::setDebounceMan(DebounceManager *pDebounceMan)
{
	theDebounceMan = nullptr;
	if(pDebounceMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< DebounceManager >();
	}
	else
	{
		theDebounceMan = pDebounceMan;
		// start the debounce timer
		theDebounceMan->start();
	}
}

DebounceManager* StateMachine::getDebounceMan()
{
	if(theDebounceMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< DebounceManager >();
		return nullptr; // not reached, prevents warning
	}
	else
	{
		return theDebounceMan;
	}

}

void StateMachine::setTaskMan(I2STskManNoRTOS *pTaskMan)
{
	if(pTaskMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< I2STskManNoRTOS >();
	}
	else
	{
		this->theTaskMan = pTaskMan;
	}

}

I2STskManNoRTOS* StateMachine::getTaskMan()
{
	if(theTaskMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< I2STskManNoRTOS >();
		return nullptr; // not reached, prevents warning
	}
	else
	{
		return theTaskMan;
	}
}

void StateMachine::evFootswitchA()
{
	if(theDebounceMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< DebounceManager >();
	}
	else
	{
		if(theDebounceMan->check_debounce())
			state->evFootswitchA(this);
	}
}

void StateMachine::evFootswitchB()
{
	if(theDebounceMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< DebounceManager >();
	}
	else
	{
		if(theDebounceMan->check_debounce())
			state->evFootswitchB(this);
	}
}

void StateMachine::evUserSwitchA()
{
	if(theDebounceMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< DebounceManager >();
	}
	else
	{
		if(theDebounceMan->check_debounce())
			state->evUserSwitchA(this);
	}

}

void StateMachine::evUserSwitchB()
{
	if(theDebounceMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< DebounceManager >();
	}
	else
	{
		if(theDebounceMan->check_debounce())
			state->evUserSwitchB(this);
	}
}

void StateMachine::evRotaryEncoderA()
{
	if(theDebounceMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< DebounceManager >();
	}
	else
	{
		if(theDebounceMan->check_debounce())
			state->evRotaryEncoderA(this);
	}
}

void StateMachine::evRotaryEncoderB()
{
	if(theDebounceMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< DebounceManager >();
	}
	else
	{
		if(theDebounceMan->check_debounce())
			state->evRotaryEncoderB(this);
	}
}
/*
StateMachine::stateFatalErrTypes StateMachine::getErrorStatus()
{
	return status;
}

void StateMachine::error_handler(StateMachine::stateFatalErrTypes pError)
{
	std::cout << "Caught error(" << pError << ") at StateMachine::error_handle()" << std::endl;
	status = pError;
	while(FOREVER)
	{
		// wait here on target
	}
}
*/


