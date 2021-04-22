/*
 * Reverb.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: chris
 */

#include <Reverb.hpp>

BasicReverb::BasicReverb()
{
	combfilter1 = new(std::nothrow)  IIRCombFilter(3460*2, 0.805, 1.0f);
	combfilter2 = new(std::nothrow)  IIRCombFilter(2988*2, 0.827, 1.0f);
	combfilter3 = new(std::nothrow)  IIRCombFilter(3882*2, 0.783, 1.0f);
	//combfilter4 = new(std::nothrow)  IIRCombFilter(4312*2, 0.764, 1.0f);

	allpass1 = new(std::nothrow)  UniCombFilter(	480  * 2, 0.7, 0.5f);
	allpass2 = new(std::nothrow)  UniCombFilter(	161  * 2, 0.7, 0.5f);
	allpass3 = new(std::nothrow)  UniCombFilter(	46   * 2, 0.7, 0.5f);
}

BasicReverb::~BasicReverb()
{

}

void BasicReverb::setWet(uint32_t pParam)
{
	float tmp = (float)pParam;
	wet = tmp / 100;
}

float BasicReverb::processSample(float pInput)
{
	float combs = 0.0f;
	float output = 0;
	if(combfilter1)	{
		combs++;
		output += combfilter1->processSample(pInput);

	}
	if(combfilter2)	{
		combs++;
		output += combfilter2->processSample(pInput);
	}
	if(combfilter3)	{
		combs++;
		output += combfilter3->processSample(pInput);
	}
/*	if(combfilter4)	{
		combs++;
		output += combfilter4->processSample(pInput);
	}*/
	output = output / combs;


	output = allpass1->processSample(output);
	output = allpass2->processSample(output);
	output = allpass3->processSample(output);

	return output;
}

#ifndef ENABLE_REVERB_BYPASS

	void BasicReverb::process_half_u16_single(	AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pRxBufSingle,
												AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pTxBufSingle)
	{
		if(pRxBufSingle != nullptr  || pTxBufSingle != nullptr)
		{
			int lSample = (int) ( (*pRxBufSingle)[0] << 16  |  (*pRxBufSingle)[1] );
			int rSample = (int) ( (*pRxBufSingle)[2] << 16 | (*pRxBufSingle)[3] );

			float sum = (float) (lSample + rSample);
			sum = (1.0f - wet ) * sum + wet * processSample(sum);


			lSample = (int) sum;
			rSample = lSample;

			//restore to buffer
			(*pTxBufSingle)[0] = (lSample >> 16) & 0xFFFF;
			(*pTxBufSingle)[1] = lSample & 0xFFFF;
			(*pTxBufSingle)[2] = (rSample >> 16) & 0xFFFF;
			(*pTxBufSingle)[3] = rSample & 0xFFFF;
		}
	}

	void BasicReverb::process_full_u16_single(	AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pRxBufSingle,
												AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pTxBufSingle)
	{
		if(pRxBufSingle != nullptr  || pTxBufSingle != nullptr)
		{
			int lSample = (int) ( (*pRxBufSingle)[4] << 16 | (*pRxBufSingle)[5] );
			int rSample = (int) ( (*pRxBufSingle)[6] << 16 | (*pRxBufSingle)[7] );

			float sum = (float) (lSample + rSample);
			sum = (1.0f - wet) * sum + wet * this->processSample(sum);

			lSample = (int) sum;
			rSample = lSample;

			//restore to buffer
			(*pRxBufSingle)[4] = (lSample >> 16) & 0xFFFF;
			(*pRxBufSingle)[5] = lSample & 0xFFFF;
			(*pRxBufSingle)[6] = (rSample >> 16) & 0xFFFF;
			(*pRxBufSingle)[7] = rSample & 0xFFFF;
		}
	}

#endif



