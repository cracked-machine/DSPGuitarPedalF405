/*
 * ResourceManager.cpp
 *
 *  Created on: 20 Apr 2021
 *      Author: chris
 */


#include <ResourceManager.hpp>
#include <new>
#include <iostream>

//void badMemAllocHandler();

//uint32_t usedmem = 0;
//const uint32_t totalmem = 128000;
//uint32_t maxthresholdmem = 80000;

uint32_t ResourceManager::usedMem = 0;

ResourceManager::ResourceManager()
{
	std::set_new_handler(ResourceManager::badMemAllocHandler);
}

void ResourceManager::badMemAllocHandler()
{
    std::cout << "Memory allocation failed, terminating\n";
    std::set_new_handler(nullptr);
    while(FOREVER)
    {
    	// spin
    }
}

void ResourceManager::addToUsedMem(uint32_t pAddition)
{
	usedMem += pAddition;
	//std::cout << "Updated RAM Usage: Total = " << ResourceManager::getUsedMem() << " bytes." << std::endl;
}


void ResourceManager::removeFromUsedMem(uint32_t pSubtract)
{
	usedMem -= pSubtract;
}


uint32_t ResourceManager::getUsedMem()
{
	return usedMem;
}

uint32_t ResourceManager::getTotalMem()
{
	return totalMem;
}

uint32_t ResourceManager::getThresholdMem()
{
	return thresholdMem;
}



#ifndef ENABLE_CPPUTEST

// declare this function, but don't define it
/*void *operator_new_blocker();
void *operator new(std::size_t) //throw (std::bad_alloc)
{
	return operator_new_blocker();
}*/


void* operator new(size_t size)
{
    std::cout << "Fatal Error: call to default operator new is forbidden" << std::endl;

    while(FOREVER)
    {
    	// spin here

    }
    void * p = nullptr;
	return p;
}

void* operator new[](size_t size)
{
    std::cout << "Fatal Error: call to default operator new[] is forbidden" << std::endl;

    while(FOREVER)
    {
    	// spin here

    }
    void * p = nullptr;
	return p;
}


//void* operator new(std::size_t) = delete;

void operator delete(void*)
{
	return;
}
#endif



