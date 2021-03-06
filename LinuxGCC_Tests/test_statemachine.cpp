/*
 *  	test_audio_buffer.cpp
 *
 *  	Created on: 5 Apr 2021
 *		
 * 		MIT License
 *
 * 		Copyright (c) [2021] [Chris Sutton]
 *
 * 		Permission is hereby granted, free of charge, to any person obtaining a copy
 * 		of this software and associated documentation files (the "Software"), to deal
 * 		in the Software without restriction, including without limitation the rights
 * 		to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * 		copies of the Software, and to permit persons to whom the Software is
 * 		furnished to do so, subject to the following conditions:
 *
 * 		The above copyright notice and this permission notice shall be included in all
 * 		copies or substantial portions of the Software.
 *
 * 		THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * 		IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * 		FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * 		AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * 		LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * 		OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * 		SOFTWARE.
 */


#include "CppUTest/TestHarness.h"
#include <StateMachine.hpp>

#include <test_hal_testenv.h>


//TIM_TypeDef *TIM14 = (TIM_TypeDef*)std::malloc(sizeof(TIM_TypeDef*));



TEST_GROUP(StateMachineGroup)
{
	void setup()
	{

	}

	void teardown()
	{

	}
};
TEST(StateMachineGroup, StateMachine_NullPtrTest)
{
	// create statemachine instance
	StateMachine *machine = new (std::nothrow) StateMachine();
	machine->setDebounceMan(nullptr);
	//CHECK(machine->getErrorStatus() == machine->NULL_DEBOUNCE_PTR);
	//delete machine;

}
TEST(StateMachineGroup, StateMachine_EnabledDisableStateTest)
{
	// create instance of timer periph for debounceman
	TIM_TypeDef *TIM14 = (TIM_TypeDef*)std::malloc(sizeof(TIM_TypeDef*));

	// create statemachine instance
	StateMachine *statemachine = new (std::nothrow) StateMachine();
/*
	// create debounce manager instance
	//DebounceManager *extctrl_debounceman_nullptr = new DebounceManager(nullptr, 100);

	DebounceManager *extctrl_debounceman = new (std::nothrow) DebounceManager(TIM14, 100);
	statemachine->setDebounceMan(extctrl_debounceman);

	//run tests
	statemachine->evFootswitchA();

	//CHECK(statemachine->getState() == statemachine->theStateList[StateMachine::FX_ENABLED]);

	TIM14->CNT = 200;

	statemachine->evFootswitchA();

	CHECK(statemachine->getState() == statemachine->theStateList[StateMachine::FX_DISABLED]);

	delete extctrl_debounceman;
	extctrl_debounceman = nullptr;
*/
//	delete statemachine;
//	statemachine = nullptr;

	free(TIM14);
	TIM14 = NULL;
}

