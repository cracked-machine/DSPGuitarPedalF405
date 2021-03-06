/*
 * FxEnabledState.hpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#ifndef STATEMACHINE_FXENABLEDSTATE_HPP_
#define STATEMACHINE_FXENABLEDSTATE_HPP_

#include <AbstractState.hpp>


class FxEnabledState : public AbstractState
{
public:


	virtual void evFootswitchA(StateMachine *machine) override;
	virtual void evFootswitchB(StateMachine *machine) override;
	virtual void evUserSwitchA(StateMachine *machine) override;
	virtual void evUserSwitchB(StateMachine *machine) override;
	virtual void evRotaryEncoderA(StateMachine *machine) override;
	virtual void evRotaryEncoderB(StateMachine *machine) override;

	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< FxEnabledState >(size))
				return malloc(size);
			else
				return nullptr;
	}
};



#endif /* STATEMACHINE_FXENABLEDSTATE_HPP_ */
