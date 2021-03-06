/*
 * AbstractState.cpp
 *
 *  Created on: Apr 12, 2021
 *      Author: chris
 */


#include <AbstractState.hpp>
#include <StateMachine.hpp>
class StateMachine;

// AbstractState class
AbstractState::~AbstractState() {}

void AbstractState::setState(StateMachine *machine, AbstractState *st)
{
	if(machine == nullptr || st == nullptr)
		error_handler();

	// set new system state
	machine->state = st;
}

void AbstractState::error_handler()
{
	do
	{
		// wait here for assistance
	}
	while(1);

}





