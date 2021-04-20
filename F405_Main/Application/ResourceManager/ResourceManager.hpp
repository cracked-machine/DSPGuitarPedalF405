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

#ifndef DISABLE_ERROR_HANDLER
#define FOREVER 1
#else
#define FOREVER 0
#endif

template<class T>
std::size_t how_many_elements(std::size_t bytes)
{
  return (bytes - ((!std::is_trivially_destructible<T>::value)*sizeof(void*))) / sizeof(T);
}

static uint32_t usedmem = 0;
static const uint32_t totalmem = 128000;
static const uint32_t maxthresholdmem = 80000;



#endif /* RESOURCEMANAGER_RESOURCEMANAGER_HPP_ */
