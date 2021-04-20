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
	IIRCombFilter(size_t pSize, float pGain);
	virtual ~IIRCombFilter();

	float processSample(float pSampleIn);

private:
	IIRCombFilterBuffer *buffer;
	float gain;
	float limit;
};

#endif /* DSP_REVERB_IIRCOMBFILTER_HPP_ */
