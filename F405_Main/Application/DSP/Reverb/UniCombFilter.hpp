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
	UniCombFilter(size_t pSize, float pGain);

	virtual ~UniCombFilter();

	float processSample(float pSampleIn);

private:
	UniCombFilterBuffer *buffer;
	float gain;
	float limit;
};

#endif /* DSP_REVERB_UNICOMBFILTER_HPP_ */

