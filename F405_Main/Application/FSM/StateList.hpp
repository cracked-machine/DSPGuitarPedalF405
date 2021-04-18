/*
 * StateList.hpp
 *
 *  Created on: 18 Apr 2021
 *      Author: chris
 */

#ifndef FSM_STATELIST_HPP_
#define FSM_STATELIST_HPP_

#include <map>

#include <AbstractState.hpp>
class AbstractState;
#include "FxDisabledState.hpp"
#include "FxEnabledState.hpp"

class StateList
{
public:

	enum statekeys
	{
		FX_DISABLED = 0,
		FX_ENABLED
	};

	AbstractState* getAt(StateList::statekeys _key);

private:
	std::map<size_t, AbstractState*> theMap = {{0, new FxDisabledState()}, {1, new FxEnabledState()}};
};


#endif /* FSM_STATELIST_HPP_ */