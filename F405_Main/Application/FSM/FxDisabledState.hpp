/*
 * FxDisabledState.hpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#ifndef FSM_FXDISABLEDSTATE_HPP_
#define FSM_FXDISABLEDSTATE_HPP_

#include "AbstractState.hpp"

class FxDisabledState : public AbstractState
{
public:


	virtual void evFootswitchA(EventMachine *machine);
	virtual void evFootswitchB(EventMachine *machine);
	virtual void evUserSwitchA(EventMachine *machine);
	virtual void evUserSwitchB(EventMachine *machine);
	virtual void evRotaryEncoderA(EventMachine *machine);
	virtual void evRotaryEncoderB(EventMachine *machine);

};


#endif /* FSM_FXDISABLEDSTATE_HPP_ */