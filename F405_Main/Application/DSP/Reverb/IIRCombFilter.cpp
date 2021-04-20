/*
 * IIRCombFilter.cpp
 *
 *  Created on: Apr 20, 2021
 *      Author: chris
 */


#include <IIRCombFilter.hpp>



IIRCombFilter::IIRCombFilter(size_t pSize, float pGain)
{
	std::cout << "Requesting BoundedVector<float> of size: " << pSize << std::endl;
	buffer = new  IIRCombFilterBuffer(pSize);
	buffer->iterator = buffer->begin();
	gain = pGain;
	limit = 1.0f * pSize;
}

IIRCombFilter::~IIRCombFilter()
{

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


