/*
 * IIRCombFilter.hpp
 *
 *  Created on: 19 Apr 2021
 *      Author: chris
 */

#ifndef DSP_REVERB_IIRCOMBFILTER_HPP_
#define DSP_REVERB_IIRCOMBFILTER_HPP_

#include <BoundedVector.hpp>
#include <AbstractFx.hpp>



typedef BoundedVector<float> IIRCombFilterBuffer;

class IIRCombFilter : public AbstractFx
{
public:
	IIRCombFilter(size_t pSize, float pGain, float pTime);
	virtual ~IIRCombFilter();

	float processSample(float pSampleIn);

	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
			if(ResourceManager::checkSystemMem< IIRCombFilter >(size))
				return malloc(size);
			else
				return nullptr;
	}


private:
	IIRCombFilterBuffer *buffer;
	float gain;
	float limit;
};

#endif /* DSP_REVERB_IIRCOMBFILTER_HPP_ */
