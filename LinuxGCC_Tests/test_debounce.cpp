/*
 * test_debounce.cpp
 *
 *  Created on: Apr 13, 2021
 *      Author: chris
 */

#include <test_hal_testenv.h>
#include "CppUTest/TestHarness.h"

#include "Debounce.hpp"



TEST_GROUP(DebounceGroup)
{
	   void setup()
	   {



	   }

	   void teardown()
	   {
	      // Uninit stuff
	   }

};

TEST(DebounceGroup, DebounceTest)
{
	TIM_TypeDef *TIM14 = (TIM_TypeDef*)std::malloc(sizeof(TIM_TypeDef*));

	DebounceManager *dman = new DebounceManager(TIM14, 100);

	bool res = false;
	dman->start();

	TIM14->CNT = 0;
	res = dman->check_debounce();
	CHECK(res == false);

	TIM14->CNT = 50;
	res = dman->check_debounce();
	CHECK(res == false);

	TIM14->CNT = 200;
	res = dman->check_debounce();
	CHECK(res == true);

	delete dman;



}

