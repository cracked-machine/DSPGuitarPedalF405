/*
 * ResourceManager.hpp
 *
 *  Created on: 20 Apr 2021
 *      Author: chris
 */

#ifndef RESOURCEMANAGER_RESOURCEMANAGER_HPP_
#define RESOURCEMANAGER_RESOURCEMANAGER_HPP_

#include <stdint.h>
#include <cstddef>
#include <type_traits>
#include <iostream>
#include <new>
#include <typeinfo>

#ifndef DISABLE_ERROR_HANDLER
#define FOREVER 1
#else
#define FOREVER 0
#endif

class ResourceManager
{

public:

	ResourceManager();

	template <typename T>
	static void notifySysNullPtr()
	{
		//std::cout << "nullptr accessing " << typeid(T).name() << std::endl;
		while(FOREVER)
		{
			// stay
		}
	}

	/*
	 * check the system has memory left before it ius allocated
	 * (called by class-level overloaded 'operator new(std::nothrow)')
	 */
	template<typename T>
	static bool checkSystemMem(std::size_t pSize)
	{

	  //return (bytes - ((!std::is_trivially_destructible<T>::value)*sizeof(void*))) / sizeof(T);
		uint32_t requestedSize = pSize;
		if(ResourceManager::usedMem + requestedSize > ResourceManager::thresholdMem)
		{
			std::cout << std::endl << typeid(T).name() << ":" << std::endl;
			std::cout << "\n\tMEMORY ALLOCATION FAILURE" << std::endl;
			std::cout << "Requested memory " << requestedSize << "bytes, is not available" << std::endl;
			std::cout << "*** System total = " << ResourceManager::usedMem << " bytes." << std::endl;
			return false;
		}
		else
		{
			ResourceManager::usedMem += requestedSize;
			std::cout << typeid(T).name() << ": " << requestedSize << " bytes." << std::endl;
			//std::cout << "Allocating " << requestedSize << " bytes." << std::endl;
			//std::cout << "*** System total = " << ResourceManager::usedMem << " bytes." << std::endl;
			return true;
		}

	}

	static bool checkSystemMem(std::size_t pSize)
	{
	  //return (bytes - ((!std::is_trivially_destructible<T>::value)*sizeof(void*))) / sizeof(T);
		uint32_t requestedSize = pSize;
		if(ResourceManager::usedMem + requestedSize > ResourceManager::thresholdMem)
		{
			std::cout << "Requested memory, " << requestedSize << "bytes, is not available" << std::endl;
			return false;
		}
		else
		{
			ResourceManager::usedMem += requestedSize;
			std::cout << "Allocating " << requestedSize << " bytes. \t\tSystem total = " << ResourceManager::usedMem << " bytes." << std::endl;
			return true;
		}

	}

	static uint32_t getUsedMem();
	static void addToUsedMem(uint32_t pAddition);
	static void removeFromUsedMem(uint32_t pSubtract);
	static uint32_t getTotalMem();
	static uint32_t getThresholdMem();
	static void badMemAllocHandler();

private:
	static uint32_t usedMem;
	static const uint32_t totalMem = 128000;
	static const uint32_t thresholdMem = (ResourceManager::totalMem - 500);
};






#endif /* RESOURCEMANAGER_RESOURCEMANAGER_HPP_ */
