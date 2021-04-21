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

//uint32_t usedmem = 0;
//const uint32_t totalmem = 128000;
//uint32_t maxthresholdmem = 80000;

uint32_t ResourceManager::usedMem = 0;


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

void initResourceManager()
{
	std::set_new_handler(badMemAllochandler);
}
#ifndef ENABLE_CPPUTEST

void CauseLinkerErrorOnCallToNew();

void* operator new(size_t size)
{
    std::cout << "Error: call to default operator new is forbidden" << std::endl;
    ResourceManager::addToUsedMem(size);
    //CauseLinkerErrorOnCallToNew();
	void * p = malloc(size);
	return p;
}

void operator delete(void*)
{
	return;
}
#endif

void badMemAllochandler()
{
    std::cout << "Memory allocation failed, terminating\n";
    std::set_new_handler(nullptr);
    while(FOREVER)
    {
    	// spin
    }
}

