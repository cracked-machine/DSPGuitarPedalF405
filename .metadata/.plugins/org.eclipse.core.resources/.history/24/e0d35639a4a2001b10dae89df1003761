/*
 * Reverb.hpp
 *
 *  Created on: Apr 20, 2021
 *      Author: chris
 */

#ifndef DSP_REVERB_REVERB_HPP_
#define DSP_REVERB_REVERB_HPP_

#include <UniCombFilter.hpp>
#include <IIRCombFilter.hpp>

class BasicReverb
{

public:
	BasicReverb();
	~BasicReverb();
	float processSample(float pInput);
private:
	IIRCombFilter *combfilter1;
	IIRCombFilter *combfilter2;
	IIRCombFilter *combfilter3;
	IIRCombFilter *combfilter4;
	UniCombFilter *allpass1;
	UniCombFilter *allpass2;
	UniCombFilter *allpass3;
};




#endif /* DSP_REVERB_REVERB_HPP_ */
