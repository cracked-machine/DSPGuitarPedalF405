/*
 * UniCombFilter.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: chris
 */


#include <UniCombFilter.hpp>



UniCombFilter::UniCombFilter(size_t pSize, float pGain, float pTime)
{
	buffer = new (std::nothrow) UniCombFilterBuffer(pSize);
	buffer->iterator = buffer->begin();
	gain = pGain;
	limit = pTime * pSize;
}

UniCombFilter::~UniCombFilter()
{

}

void UniCombFilter::zeroBuffer()
{
	//this->zeroBuffer();
	buffer->iterator = buffer->begin();
}

float UniCombFilter::processSample(float pSampleIn)
{
	float Xn = pSampleIn;

	float readback = *(buffer->iterator);
	readback += (-gain) * Xn;

	float tmp = readback * gain + Xn;

	// store the result
	*(buffer->iterator) = tmp;

	// iterate the buffer position, make sure not to overrun
	buffer->iterator++;
	if (buffer->iterator >= buffer->end())
		buffer->iterator = buffer->begin();

	return readback;

}


