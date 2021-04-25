/*
 * FxDisabledState.hpp
 *
 *  Created on: 13 Apr 2021
 *      Author: chris
 */

#ifndef STATEMACHINE_FXDISABLEDSTATE_HPP_
#define STATEMACHINE_FXDISABLEDSTATE_HPP_

#include <AbstractState.hpp>


class FxDisabledState : public AbstractState
{
public:

	   void evFootswitchA(StateMachine *machine) override;
	   void evFootswitchB(StateMachine *machine) override;
	   void evUserSwitchA(StateMachine *machine) override;
	   void evUserSwitchB(StateMachine *machine) override;
	   void evRotaryEncoderA(StateMachine *machine) override;
	   void evRotaryEncoderB(StateMachine *machine) override;

		/*
		 * check there is system memory available before allocation or return nullptr
		 */
		void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
				if(ResourceManager::checkSystemMem< FxDisabledState >(size))
					return malloc(size);
				else
					return nullptr;
		}
};


#endif /* STATEMACHINE_FXDISABLEDSTATE_HPP_ */
