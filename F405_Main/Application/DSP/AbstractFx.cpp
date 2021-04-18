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
void AbstractFx::process_half_u16(	array<uint16_t, STEREO_BLOCK_SIZE_U16> *pRxBuf,
									array<uint16_t, STEREO_BLOCK_SIZE_U16> *pTxBuf)
{
	// do something for first half samples here if needed
	for(size_t i = 0; i < BLOCK_SIZE_U16; i++ )
	{
		(*pTxBuf)[i] = (*pRxBuf)[i];
	}
}

// default passthru implementation for second half of data
void AbstractFx::process_full_u16(	array<uint16_t, STEREO_BLOCK_SIZE_U16> *pRxBuf,
									array<uint16_t, STEREO_BLOCK_SIZE_U16> *pTxBuf)
{
	// do something for second half samples here if needed
	for(size_t i = BLOCK_SIZE_U16; i < STEREO_BLOCK_SIZE_U16; i++ )
	{
		(*pTxBuf)[i] = (*pRxBuf)[i];
	}
}

void AbstractFx::process_all_u16			(	array<uint16_t, STEREO_BLOCK_SIZE_U16> *pRxBuf,
									array<uint16_t, STEREO_BLOCK_SIZE_U16> *pTxBuf)
{
	// do something for all samples here if needed
}
