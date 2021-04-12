/*
 * AbstractState.hpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */

#pragma once
#include <EventMachine.hpp>

#include <stdint.h>

class EventMachine;


class AbstractState
{

public:

	virtual void evFootswitchA(EventMachine *machine) = 0;
	virtual void evFootswitchB(EventMachine *machine) = 0;
	virtual void evUserSwitchA(EventMachine *machine) = 0;
	virtual void evUserSwitchB(EventMachine *machine) = 0;
	virtual void evRotaryEncoderA(EventMachine *machine) = 0;
	virtual void evRotaryEncoderB(EventMachine *machine) = 0;

	virtual ~AbstractState();

protected:

	void setState(EventMachine *machine, AbstractState *st);

};






