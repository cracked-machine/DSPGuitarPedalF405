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
#include <StaticIIRCombFilter.hpp>
#include <StaticUniCombFilter.hpp>

// debug use only
//#define ENABLE_REVERB_BYPASS

class BasicReverb : public AbstractFx
{

public:
	BasicReverb();
	~BasicReverb();
	float processSample(float pInput);

#ifndef ENABLE_REVERB_BYPASS
	void process_half_u16_single(AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pRxBufSingle,
								 AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pTxBufSingle) override;

	void process_full_u16_single(AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pRxBufSingle,
								 AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pTxBufSingle) override;
#endif

	void zeroAllBuffers();

private:
	IIRCombFilter *combfilter1;
	IIRCombFilter *combfilter2;
	IIRCombFilter *combfilter3;
	IIRCombFilter *combfilter4;

	UniCombFilter *allpass1;
	UniCombFilter *allpass2;
	UniCombFilter *allpass3;

/*
	StaticIIRCombFilter1 *combfilter1;
	StaticIIRCombFilter2 *combfilter2;
	StaticIIRCombFilter3 *combfilter3;
//	StaticIIRCombFilter4 *combfilter4;

	StaticUniCombFilter1 *allpass1;
	StaticUniCombFilter2 *allpass2;
	StaticUniCombFilter3 *allpass3;
*/
	float wet = 0.4f;


public:

	void setWet(uint32_t pParam);
	/*
	 * check there is system memory available before allocation or return nullptr
	 */
	void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
		if(ResourceManager::checkSystemMem< BasicReverb >(size))
			return malloc(size);
		else
			return nullptr;
	}
};




#endif /* DSP_REVERB_REVERB_HPP_ */
