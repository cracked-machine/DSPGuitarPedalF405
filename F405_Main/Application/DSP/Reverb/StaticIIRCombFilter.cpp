/*
 * StaticIIRCombFilter.cpp
 *
 *  Created on: Apr 23, 2021
 *      Author: chris
 */

#include <StaticIIRCombFilter.hpp>


/*
 * 		StaticIIRCombFilter1
 */
StaticIIRCombFilter1::StaticIIRCombFilter1()
{
	ptr = 0;
	gain = 0.805;
	limit = 1.0f * StaticIIRCombFilter1_SIZE;
}

StaticIIRCombFilter1::~StaticIIRCombFilter1()
{

}

void StaticIIRCombFilter1::zeroBuffer()
{

}

float StaticIIRCombFilter1::processSample(float pSampleIn)
{
	float Xn = pSampleIn;

	float readback = buffer[ptr];

	float tmp = Xn + (gain * readback);

	buffer[ptr] = tmp;
	ptr++;

	if (buffer[ptr] >= buffer.size())
		ptr = 0;
	return readback;
}

/*
 * 		StaticIIRCombFilter2
 */

StaticIIRCombFilter2::StaticIIRCombFilter2()
{
	ptr = 0;
	gain = 0.827;
	limit = 1.0f * StaticIIRCombFilter2_SIZE;
}

StaticIIRCombFilter2::~StaticIIRCombFilter2()
{

}


void StaticIIRCombFilter2::zeroBuffer()
{

}

float StaticIIRCombFilter2::processSample(float pSampleIn)
{
	float Xn = pSampleIn;

	float readback = buffer[ptr];

	float tmp = Xn + (gain * readback);

	buffer[ptr] = tmp;
	ptr++;

	if (buffer[ptr] >= buffer.size())
		ptr = 0;
	return readback;
}

/*
 * StaticIIRCombFilter3
 */

StaticIIRCombFilter3::StaticIIRCombFilter3()
{
	ptr = 0;
	gain = 0.783;
	limit = 1.0f * StaticIIRCombFilter3_SIZE;
}

StaticIIRCombFilter3::~StaticIIRCombFilter3()
{

}


void StaticIIRCombFilter3::zeroBuffer()
{
	//this->zeroBuffer();
	//buffer->iterator = buffer->begin();
}

float StaticIIRCombFilter3::processSample(float pSampleIn)
{
	float Xn = pSampleIn;

	float readback = buffer[ptr];

	float tmp = Xn + (gain * readback);

	buffer[ptr] = tmp;
	ptr++;

	if (buffer[ptr] >= buffer.size())
		ptr = 0;
	return readback;
}

/*
 * 		StaticIIRCombFilter4
 */

StaticIIRCombFilter4::StaticIIRCombFilter4()
{
	ptr = 0;
	gain = 0.764;
	limit = 1.0f * StaticIIRCombFilter4_SIZE;
}

StaticIIRCombFilter4::~StaticIIRCombFilter4()
{

}


void StaticIIRCombFilter4::zeroBuffer()
{

}

float StaticIIRCombFilter4::processSample(float pSampleIn)
{
	float Xn = pSampleIn;

	float readback = buffer[ptr];

	float tmp = Xn + (gain * readback);

	buffer[ptr] = tmp;
	ptr++;

	if (buffer[ptr] >= buffer.size())
		ptr = 0;
	return readback;
}


