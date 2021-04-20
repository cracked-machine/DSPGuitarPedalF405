/*
 * ResourceManager.cpp
 *
 *  Created on: 20 Apr 2021
 *      Author: chris
 */


#include <ResourceManager.hpp>
#include <new>
#include <iostream>

void badMemAllochandler();

void initResourceManager()
{
	std::set_new_handler(badMemAllochandler);
}

void* operator new(size_t size)
{
    std::cout << "Overloading new operator with size: " << size << std::endl;
	//void * p = ::operator new(size);
	void * p = malloc(size); //will also work fine
	usedmem += size;
	return p;
}

void operator delete(void*)
{
	return;
}

void badMemAllochandler()
{
    std::cout << "Memory allocation failed, terminating\n";
    std::set_new_handler(nullptr);
    while(FOREVER)
    {
    	// spin
    }
}

