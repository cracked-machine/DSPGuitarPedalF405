/*
 * AbstractState.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */


#include <AbstractState.hpp>

#include "StateMachine.hpp"
class StateMachine;

// AbstractState class
AbstractState::~AbstractState() {}

void AbstractState::setState(StateMachine *machine, AbstractState *st)
{
	machine->state = st;
}





