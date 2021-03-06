/*
 * test_debounce.cpp
 *
 *  Created on: Apr 13, 2021
 *      Author: chris
 */

#include <test_hal_testenv.h>
#include "CppUTest/TestHarness.h"

#include "Debounce.hpp"



TEST_GROUP(DebounceManagerGroup)
{
	   void setup()
	   {

	   }

	   void teardown()
	   {
	      // Uninit stuff
	   }

};

void initTimer(TIM_TypeDef *TIM14)
{
	/*
	   TIM14->CR1 = 0;			//!< TIM control register 1,              Address offset: 0x00
	   TIM14->CR2 = 0;         //!< TIM control register 2,              Address offset: 0x04
	   TIM14->SMCR = 0;        //!< TIM slave mode control register,     Address offset: 0x08
	   TIM14->DIER = 0;        //!< TIM DMA/interrupt enable register,   Address offset: 0x0C
		TIM14->SR = 0;          //!< TIM status register,                 Address offset: 0x10
		TIM14->EGR = 0;         //!< TIM event generation register,       Address offset: 0x14
		TIM14->CCMR1 = 0;       //!< TIM capture/compare mode register 1, Address offset: 0x18
		TIM14->CCMR2 = 0;       //!< TIM capture/compare mode register 2, Address offset: 0x1C
		TIM14->CCER = 0;        //!< TIM capture/compare enable register, Address offset: 0x20
		TIM14->CNT = 0;         //!< TIM counter register,                Address offset: 0x24
		TIM14->PSC = 0;         //!< TIM prescaler,                       Address offset: 0x28
		TIM14->ARR = 0;         //!< TIM auto-reload register,            Address offset: 0x2C
		TIM14->RCR = 0;         //!< TIM repetition counter register,     Address offset: 0x30
		TIM14->CCR1 = 0;        //!< TIM capture/compare register 1,      Address offset: 0x34
		TIM14->CCR2 = 0;        //!< TIM capture/compare register 2,      Address offset: 0x38
		TIM14->CCR3 = 0;        //!< TIM capture/compare register 3,      Address offset: 0x3C
		TIM14->CCR4 = 0;        //!< TIM capture/compare register 4,      Address offset: 0x40
		TIM14->BDTR = 0;        //!< TIM break and dead-time register,    Address offset: 0x44
		TIM14->DCR = 0;         //!< TIM DMA control register,            Address offset: 0x48
		TIM14->DMAR = 0;        //!< TIM DMA address for full transfer,   Address offset: 0x4C
		TIM14->OR = 0;          //!< TIM option register,                 Address offset: 0x50
		*/
}

TEST(DebounceManagerGroup, DebounceManager_NullPtrTest)
{
	DebounceManager *dman = new (std::nothrow) DebounceManager(nullptr, 100);
	dman->start();
	CHECK(dman->getErrorStatus() == dman->NULL_TIMER_ERR);
	//delete dman;
	//dman = nullptr;
}

TEST(DebounceManagerGroup, DebounceManager_DelayLowBoundsTest)
{
	TIM_TypeDef *TIM14 = (TIM_TypeDef*)std::malloc(sizeof(TIM_TypeDef*));

	DebounceManager *dman = new (std::nothrow) DebounceManager(TIM14, -1);
	dman->start();
	CHECK(dman->isStarted());
	//delete dman;
	//dman = nullptr;
}

TEST(DebounceManagerGroup, DebounceManager_DelayHighboundsTest)
{
	TIM_TypeDef *TIM14 = (TIM_TypeDef*)std::malloc(sizeof(TIM_TypeDef*));

	DebounceManager *dman = new (std::nothrow) DebounceManager(TIM14, 65536);
	dman->start();
	CHECK(dman->isStarted());
	//delete dman;
	//dman = nullptr;
}


TEST(DebounceManagerGroup, DebounceManager_MainDelayTest)
{
	TIM_TypeDef *TIM14 = (TIM_TypeDef*)std::malloc(sizeof(TIM_TypeDef*));

	DebounceManager *dman = new (std::nothrow) DebounceManager(TIM14, 100);

	bool res = false;
	dman->start();

	TIM14->CNT = 0;
	res = dman->check_debounce();
	//CHECK_FALSE(res);

	TIM14->CNT = 50;
	res = dman->check_debounce();
	//CHECK_FALSE(res);

	TIM14->CNT = 200;
	res = dman->check_debounce();
	CHECK(res);

	//delete dman;
	//dman = nullptr;
}

