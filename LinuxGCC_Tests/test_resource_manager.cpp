/*
 * test_resource_manager.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: chris
 */


#include "CppUTest/TestHarness.h"

#include <test_hal_testenv.h>

#include "ResourceManager.hpp"
#include <I2STaskManager.hpp>

#include <StateMachine.hpp>
#include <Debounce.hpp>



TEST_GROUP(ResourceManGroup)
{
};

TEST(ResourceManGroup, ResourceManTest)
{
	I2STskManNoRTOS *i2s_taskman_nortos;

	StateMachine *statemachine = NULL;
	DebounceManager *extctrl_debounceman;

	i2s_taskman_nortos = new(std::nothrow) I2STskManNoRTOS();

	TIM_TypeDef *TIM14 = (TIM_TypeDef*)std::malloc(sizeof(TIM_TypeDef*));
	extctrl_debounceman = new(std::nothrow)  DebounceManager(TIM14, 200);

	statemachine = new(std::nothrow)  StateMachine();
	statemachine->setDebounceMan(extctrl_debounceman);


	i2s_taskman_nortos->setStateMachine(statemachine);


	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Total System Bytes Used: " << ResourceManager::getUsedMem() << std::endl;

	delete extctrl_debounceman;

}

/*
 * 	void *operator new(std::size_t count) {
		std::cout << "allocating " << count << " bytes, " << how_many_elements<IIRFilterFx>(count) << " items\n";
		return ::operator new[](count);
	}
 */
