/*
 * UniCombFilter.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: chris
 */


#include <UniCombFilter.hpp>



UniCombFilter::UniCombFilter(size_t pSize, float pGain)
{
	buffer = new UniCombFilterBuffer(pSize);
	buffer->iterator = buffer->begin();
	gain = pGain;
	limit = 1.0f * pSize;
}

UniCombFilter::~UniCombFilter()
{

}

float UniCombFilter::processSample(float pSampleIn)
{
	float Xn = pSampleIn;

	float readback = *(buffer->iterator);
	readback += (-gain) * Xn;

	float tmp = readback * gain + Xn;

	*(buffer->iterator) = tmp;
	buffer->iterator++;

	if (*(buffer->iterator) == limit)
		buffer->iterator = buffer->begin();

	return readback;

}

