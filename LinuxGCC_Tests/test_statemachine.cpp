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

TEST(StateMachineGroup, StateMachineTest)
{
	// create instance of timer periph for debounceman
	TIM_TypeDef *TIM14 = (TIM_TypeDef*)std::malloc(sizeof(TIM_TypeDef*));

	// create statemachine instance
	StateMachine *extctrlMachine = new StateMachine();

	// create debounce manager instance
	DebounceManager *extctrl_debounceman = new DebounceManager(TIM14, 100);
	extctrlMachine->setDebounceMan(extctrl_debounceman);



	//run tests
	extctrlMachine->evFootswitchA();

	CHECK(extctrlMachine->getState() == extctrlMachine->theStateList[StateMachine::FX_ENABLED]);

	TIM14->CNT = 200;

	extctrlMachine->evFootswitchA();

	CHECK(extctrlMachine->getState() == extctrlMachine->theStateList[StateMachine::FX_DISABLED]);

	delete extctrl_debounceman;
	extctrl_debounceman = nullptr;

	delete extctrlMachine;
	extctrlMachine = nullptr;

	free(TIM14);
	TIM14 = NULL;
}

