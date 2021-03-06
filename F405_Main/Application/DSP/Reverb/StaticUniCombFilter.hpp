/*
 * StaticUniCombFilter.hpp
 *
 *  Created on: Apr 23, 2021
 *      Author: chris
 */

#ifndef DSP_REVERB_STATICUNICOMBFILTER_HPP_
#define DSP_REVERB_STATICUNICOMBFILTER_HPP_

#include <AbstractFx.hpp>

class StaticUniCombFilter1 : public AbstractFx
{
public:
	StaticUniCombFilter1();

	virtual ~StaticUniCombFilter1();

	float processSample(float pSampleIn);

	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< StaticUniCombFilter1 >(size))
				return malloc(size);
			else
				return nullptr;
	}

	void zeroBuffer();
private:
	int ptr;
	static const size_t StaticUniCombFilter1_SIZE = 480 * 2;
	std::array<float, StaticUniCombFilter1_SIZE> buffer{};
	float gain;
	float limit;
};

class StaticUniCombFilter2 : public AbstractFx
{
public:
	StaticUniCombFilter2();

	virtual ~StaticUniCombFilter2();

	float processSample(float pSampleIn);

	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< StaticUniCombFilter2 >(size))
				return malloc(size);
			else
				return nullptr;
	}

	void zeroBuffer();
private:
	int ptr;
	static const size_t StaticUniCombFilter2_SIZE = 161 * 2;
	std::array<float, StaticUniCombFilter2_SIZE> buffer{};
	float gain;
	float limit;
};

class StaticUniCombFilter3 : public AbstractFx
{
public:
	StaticUniCombFilter3();

	virtual ~StaticUniCombFilter3();

	float processSample(float pSampleIn);

	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< StaticUniCombFilter3 >(size))
				return malloc(size);
			else
				return nullptr;
	}

	void zeroBuffer();
private:
	int ptr;
	static const size_t StaticUniCombFilter3_SIZE = 46 *2;
	std::array<float, StaticUniCombFilter3_SIZE> buffer{};
	float gain;
	float limit;
};




#endif /* DSP_REVERB_STATICUNICOMBFILTER_HPP_ */
