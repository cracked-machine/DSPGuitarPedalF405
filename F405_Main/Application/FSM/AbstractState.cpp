/*
 * AbstractState.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */


#include <AbstractState.hpp>


// AbstractState class
AbstractState::~AbstractState() {}

void AbstractState::setState(EventMachine *machine, AbstractState *state)
{
  machine->state = state;
}





