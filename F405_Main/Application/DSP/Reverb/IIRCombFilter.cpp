/*
 * IIRCombFilter.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: chris
 */


#include <IIRCombFilter.hpp>


IIRCombFilter::IIRCombFilter(size_t pSize, float pGain, float pTime)
{

	buffer = new (std::nothrow)  IIRCombFilterBuffer(pSize);

	buffer->iterator = buffer->begin();
	gain = pGain;
	limit = pTime * pSize;
}

IIRCombFilter::~IIRCombFilter()
{

}


void IIRCombFilter::zeroBuffer()
{
	//this->zeroBuffer();
	buffer->iterator = buffer->begin();
}

float IIRCombFilter::processSample(float pSampleIn)
{
	float Xn = pSampleIn;

	float readback = *(buffer->iterator);

	float tmp = Xn + (gain * readback);

	*(buffer->iterator) = tmp;
	buffer->iterator++;

	if (buffer->iterator >= buffer->end())
		buffer->iterator = buffer->begin();
	return readback;
}


