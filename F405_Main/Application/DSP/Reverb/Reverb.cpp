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
	/*
	float output = (	combfilter1->processSample(pInput) +
						combfilter2->processSample(pInput) +
						combfilter3->processSample(pInput)// +
						//combfilter4->processSample(pInput)
						)
						/3.0f;
*/

	output = allpass1->processSample(output);
	output = allpass2->processSample(output);
	output = allpass3->processSample(output);
	output *= outputGain;
	return output;
}

void BasicReverb::process_half_u16(	AudioBlockU16< FULL_BLK_SIZE_U16 > *pRxBuf,
									AudioBlockU16< FULL_BLK_SIZE_U16 > *pTxBuf)
{

//	for(size_t i = 0; i < pRxBuf->size()-4; i+=4)
	for( size_t i = 0; i < STEREO_CH_SIZE_U16 - 4; i += 4 )
	{

		int lSample = (int) ( (*pRxBuf)[i+0] << 16  |  (*pRxBuf)[i+1] );
		int rSample = (int) ( (*pRxBuf)[i+2] << 16 | (*pRxBuf)[i+3] );

		float sum = (float) (lSample + rSample);
		sum = (1.0f - wet ) * sum + wet * processSample(sum);

		lSample = (int) sum;
		rSample = lSample;

		//restore to buffer
		(*pTxBuf)[i+0] = (lSample >> 16) & 0xFFFF;
		(*pTxBuf)[i+1] = lSample & 0xFFFF;
		(*pTxBuf)[i+2] = (rSample >> 16) & 0xFFFF;
		(*pTxBuf)[i+3] = rSample & 0xFFFF;
	}
}

void BasicReverb::process_full_u16(	AudioBlockU16< FULL_BLK_SIZE_U16 > *pRxBuf,
									AudioBlockU16< FULL_BLK_SIZE_U16 > *pTxBuf)
{

	//for(size_t i = 0; i < pRxBuf->size()-4; i+=4)
	for( size_t i = STEREO_CH_SIZE_U16; i < FULL_BLK_SIZE_U16 - 4; i += 4 )
	{
		int lSample = (int) ( (*pRxBuf)[i+4] << 16 | (*pRxBuf)[i+5] );
		int rSample = (int) ( (*pRxBuf)[i+6] << 16 | (*pRxBuf)[i+7] );

		float sum = (float) (lSample + rSample);
		sum = (1.0f - wet) * sum + wet * this->processSample(sum);
		lSample = (int) sum;
		rSample = lSample;

		//restore to buffer
		(*pTxBuf)[i+4] = (lSample >> 16) & 0xFFFF;
		(*pTxBuf)[i+5] = lSample & 0xFFFF;
		(*pTxBuf)[i+6] = (rSample >> 16) & 0xFFFF;
		(*pTxBuf)[i+7] = rSample & 0xFFFF;
	}

}

