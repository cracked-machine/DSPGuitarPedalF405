/*
 * StaticUniCombFilter.cpp
 *
 *  Created on: Apr 23, 2021
 *      Author: chris
 */


#include <StaticUniCombFilter.hpp>

/*
 * 		StaticUniCombFilter1
 */

StaticUniCombFilter1::StaticUniCombFilter1()
{
	ptr = 0;
	gain = 0.7;
	limit = 1.0f * StaticUniCombFilter1_SIZE;
}

StaticUniCombFilter1::~StaticUniCombFilter1()
{

}

void StaticUniCombFilter1::zeroBuffer()
{

}

float StaticUniCombFilter1::processSample(float pSampleIn)
{
	float Xn = pSampleIn;

	float readback = buffer[ptr];
	readback += (-gain) * Xn;

	float tmp = readback * gain + Xn;

	buffer[ptr] = tmp;
	ptr++;

	if (buffer[ptr] >= buffer.size())
		ptr = 0;

	return readback;

}


/*
 * 		StaticUniCombFilter2
 */

StaticUniCombFilter2::StaticUniCombFilter2()
{
	ptr = 0;
	gain = 0.7;
	limit = 1.0f * StaticUniCombFilter2_SIZE;
}

StaticUniCombFilter2::~StaticUniCombFilter2()
{

}

void StaticUniCombFilter2::zeroBuffer()
{

}

float StaticUniCombFilter2::processSample(float pSampleIn)
{
	float Xn = pSampleIn;

	float readback = buffer[ptr];
	readback += (-gain) * Xn;

	float tmp = readback * gain + Xn;

	buffer[ptr] = tmp;
	ptr++;

	if (buffer[ptr] >= buffer.size())
		ptr = 0;

	return readback;

}

/*
 * 		StaticUniCombFilter3
 */

StaticUniCombFilter3::StaticUniCombFilter3()
{
	ptr = 0;
	gain = 0.7;
	limit = 1.0f * StaticUniCombFilter3_SIZE;
}

StaticUniCombFilter3::~StaticUniCombFilter3()
{

}

void StaticUniCombFilter3::zeroBuffer()
{

}

float StaticUniCombFilter3::processSample(float pSampleIn)
{
	float Xn = pSampleIn;

	float readback = buffer[ptr];
	readback += (-gain) * Xn;

	float tmp = readback * gain + Xn;

	buffer[ptr] = tmp;
	ptr++;

	if (buffer[ptr] >= buffer.size())
		ptr = 0;

	return readback;

}

