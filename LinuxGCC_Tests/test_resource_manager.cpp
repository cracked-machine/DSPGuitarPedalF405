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
	CHECK(get_number_bytes<uint8_t>() == 1);
	CHECK(get_number_bytes<short>() == 2);
	CHECK(get_number_bytes<int>() == 4);
	CHECK(get_number_bytes<long>() == 8);



}

/*
 * 	void *operator new(std::size_t count) {
		std::cout << "allocating " << count << " bytes, " << how_many_elements<IIRFilterFx>(count) << " items\n";
		return ::operator new[](count);
	}
 */
