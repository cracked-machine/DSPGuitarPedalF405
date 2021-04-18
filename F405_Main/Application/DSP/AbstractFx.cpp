/*
 * AbstractFx.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */


#include "AbstractFx.hpp"


AbstractFx::AbstractFx()
{

}

AbstractFx::~AbstractFx()
{

}

// default passthru implementation for first half of data
void AbstractFx::process_half_u16(	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
									StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf)
{
	// do something for first half samples here if needed
	for(size_t i = 0; i < HALF_BLK_SIZE_U16; i++ )
	{
		(*pTxBuf)[i] = (*pRxBuf)[i];
	}
}

// default passthru implementation for second half of data
void AbstractFx::process_full_u16(	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
									StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf)
{
	// do something for second half samples here if needed
	for(size_t i = HALF_BLK_SIZE_U16; i < FULL_BLK_SIZE_U16; i++ )
	{
		(*pTxBuf)[i] = (*pRxBuf)[i];
	}
}

void AbstractFx::process_all_u16(	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
									StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf)
{
	// do something for all samples here if needed
}
