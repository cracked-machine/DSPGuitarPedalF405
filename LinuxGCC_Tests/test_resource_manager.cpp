/*
 * test_resource_manager.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: chris
 */


#include "CppUTest/TestHarness.h"

#include "ResourceManager.hpp"



TEST_GROUP(ResourceManGroup)
{
};

TEST(ResourceManGroup, ResourceManTest)
{
	ResourceManager::checkSystemMem< int >(10);


}

/*
 * 	void *operator new(std::size_t count) {
		std::cout << "allocating " << count << " bytes, " << how_many_elements<IIRFilterFx>(count) << " items\n";
		return ::operator new[](count);
	}
 */