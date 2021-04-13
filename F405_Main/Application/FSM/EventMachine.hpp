/*
 * EventMachine.hpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */

#ifndef INC_EVENTMACHINE_HPP_
#define INC_EVENTMACHINE_HPP_
#pragma once

#include <AbstractState.hpp>
#include <array>




class AbstractState;

class EventMachine
{
	friend class AbstractState;
public:
	EventMachine();
	~EventMachine();

	void evFootswitchA();
	void evFootswitchB();
	void evUserSwitchA();
	void evUserSwitchB();
	void evRotaryEncoderA();
	void evRotaryEncoderB();

	std::array<AbstractState*, 2> states_list;

	enum states_enum
	{
		FX_DISABLED,
		FX_ENABLED
	};


	AbstractState* getState();
private:
	AbstractState* state;
};






#endif /* INC_EVENTMACHINE_HPP_ */