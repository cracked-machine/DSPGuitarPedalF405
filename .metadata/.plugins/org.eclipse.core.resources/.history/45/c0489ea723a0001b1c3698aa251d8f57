/*
 * test_debounce.cpp
 *
 *  Created on: Apr 13, 2021
 *      Author: chris
 */

#include "CppUTest/TestHarness.h"

#include "Debounce.hpp"
#include "test_debounce.h"

TIM_TypeDef *TIM14 = (TIM_TypeDef*)std::malloc(sizeof(TIM_TypeDef*));
//TIM_TypeDef *TIM14;




DebounceManager debounceManagerTim14 = {DebounceManager(TIM14, 100)};

TEST_GROUP(DebounceGroup)
{
	   void setup()
	   {
		   	TIM14->CR1 =	0;
		   	TIM14->CR2 = 	0;
		   	TIM14->SMCR = 	0;
		   	TIM14->DIER = 	0;
		   	TIM14->SR 	= 	0;
		   	TIM14->EGR=    0;
		   	TIM14->CCMR1=    0;
		   	TIM14->CCMR2=    0;
		   	TIM14->CCER=    0;
		   	TIM14->CNT=    0;
		   	TIM14->PSC=    0;
		   	TIM14->ARR=    0;
		   	TIM14->RCR=    0;
		   	TIM14->CCR1=    0;
		   	TIM14->CCR2=    0;
		   	TIM14->CCR3=    0;
		   	TIM14->CCR4=    0;
		   	TIM14->BDTR=    0;
		   	TIM14->DCR=    0;
		   	TIM14->DMAR=    0;
		   	TIM14->OR=    0;
	   }

	   void teardown()
	   {
	      // Uninit stuff
	   }

};

TEST(DebounceGroup, DebounceTest)
{
	bool res = false;
	debounceManagerTim14.start();

	TIM14->CNT = 0;
	res = debounceManagerTim14.check_debounce();
	CHECK(res == false);

	TIM14->CNT = 50;
	res = debounceManagerTim14.check_debounce();
	CHECK(res == false);

	TIM14->CNT = 200;
	res = debounceManagerTim14.check_debounce();
	CHECK(res == true);




}

