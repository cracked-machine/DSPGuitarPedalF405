/*
 * UniCombFilter.hpp
 *
 *  Created on: 19 Apr 2021
 *      Author: chris
 */

#ifndef DSP_REVERB_UNICOMBFILTER_HPP_
#define DSP_REVERB_UNICOMBFILTER_HPP_

#include <BoundedVector.hpp>
#include <AbstractFx.hpp>


typedef BoundedVector<float> UniCombFilterBuffer;

class UniCombFilter : public AbstractFx
{
public:
	UniCombFilter(size_t pSize, float pGain, float pTime);

	virtual ~UniCombFilter();

	float processSample(float pSampleIn);

	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< UniCombFilter >(size))
				return malloc(size);
			else
				return nullptr;
	}

	void zeroBuffer();
private:
	UniCombFilterBuffer *buffer;
	float gain;
	float limit;
};

#endif /* DSP_REVERB_UNICOMBFILTER_HPP_ */

