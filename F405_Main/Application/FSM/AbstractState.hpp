/*
 * AbstractState.hpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */

#pragma once


// include the GPIO user labels generated by Cube (if we're building for target)
#ifdef USE_HAL_DRIVER
	#include "main.h"
#endif


#include <stdint.h>


class StateMachine;


class AbstractState
{

public:

	virtual void evFootswitchA(StateMachine *machine) = 0;
	virtual void evFootswitchB(StateMachine *machine) = 0;
	virtual void evUserSwitchA(StateMachine *machine) = 0;
	virtual void evUserSwitchB(StateMachine *machine) = 0;
	virtual void evRotaryEncoderA(StateMachine *machine) = 0;
	virtual void evRotaryEncoderB(StateMachine *machine) = 0;

	virtual ~AbstractState();

protected:

	void setState(StateMachine *machine, AbstractState *st);

};






