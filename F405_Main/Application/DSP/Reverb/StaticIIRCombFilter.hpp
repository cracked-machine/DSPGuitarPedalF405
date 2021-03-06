/*
 * StaticIIRCombFilter.hpp
 *
 *  Created on: Apr 23, 2021
 *      Author: chris
 */

#ifndef DSP_REVERB_STATICIIRCOMBFILTER_HPP_
#define DSP_REVERB_STATICIIRCOMBFILTER_HPP_

/*
const size_t staticIIRCombFilterSize1 = 3460*2;
float staticIIRCombFilterGain1 = 0.805;
float staticIIRCombFilterTime1 = 1.0f;

float staticIIRCombFilterSize2 = 2988*2;
float staticIIRCombFilterGain2 = 0.827;
float staticIIRCombFilterTime2 = 1.0f;

float staticIIRCombFilterSize3 = 3882*2;
float staticIIRCombFilterGain3 = 0.783;
float staticIIRCombFilterTime3 = 1.0f;

float staticIIRCombFilterSize4 = 4312*2;
float staticIIRCombFilterGain4 = 0.764;
float staticIIRCombFilterTime4 = 1.0f;
*/


#include <AbstractFx.hpp>


/*
 * 			StaticIIRCombFilter1
 */

class StaticIIRCombFilter1 : public AbstractFx
{
public:
	StaticIIRCombFilter1();
	virtual ~StaticIIRCombFilter1();

	float processSample(float pSampleIn);

	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< StaticIIRCombFilter1 >(size))
				return malloc(size);
			else
				return nullptr;
	}

	void zeroBuffer();
private:

	static const size_t StaticIIRCombFilter1_SIZE = 3460*2;
	std::array<float, StaticIIRCombFilter1_SIZE> buffer{};
	float gain;
	float limit;
	int ptr;
};

/*
 * 		StaticIIRCombFilter2
 */

class StaticIIRCombFilter2 : public AbstractFx
{
public:
	StaticIIRCombFilter2();
	virtual ~StaticIIRCombFilter2();

	float processSample(float pSampleIn);

	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< StaticIIRCombFilter2 >(size))
				return malloc(size);
			else
				return nullptr;
	}

	void zeroBuffer();
private:
	static const size_t StaticIIRCombFilter2_SIZE = 2988*2;
	std::array<float, StaticIIRCombFilter2_SIZE> buffer{};
	float gain;
	float limit;
	int ptr;
};

/*
 * 		StaticIIRCombFilter3
 */

class StaticIIRCombFilter3 : public AbstractFx
{
public:
	StaticIIRCombFilter3();
	virtual ~StaticIIRCombFilter3();

	float processSample(float pSampleIn);

	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< StaticIIRCombFilter3 >(size))
				return malloc(size);
			else
				return nullptr;
	}

	void zeroBuffer();
private:
	static const size_t StaticIIRCombFilter3_SIZE = 3882*2;
	std::array<float, StaticIIRCombFilter3_SIZE> buffer{};
	float gain;
	float limit;
	int ptr;
};

/*
 * 		StaticIIRCombFilter4
 */

class StaticIIRCombFilter4 : public AbstractFx
{
public:
	StaticIIRCombFilter4();
	virtual ~StaticIIRCombFilter4();

	float processSample(float pSampleIn);

	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< StaticIIRCombFilter4 >(size))
				return malloc(size);
			else
				return nullptr;
	}

	void zeroBuffer();
private:

	static const size_t StaticIIRCombFilter4_SIZE = 4312*2;
	std::array<float, StaticIIRCombFilter4_SIZE> buffer{};
	float gain;
	float limit;
	int ptr;
};



#endif /* DSP_REVERB_STATICIIRCOMBFILTER_HPP_ */
