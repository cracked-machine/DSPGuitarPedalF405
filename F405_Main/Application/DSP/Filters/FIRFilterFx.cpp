/*
 * IIRFilterFx.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */




#include <FIRFilterFx.hpp>

void FIRFilterFx::process_half_u16_block(	AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
									AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock)
{
	if(pRxBufBlock == nullptr || pTxBufBlock == nullptr)
		error_handler();

}

void FIRFilterFx::process_full_u16_block(	AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
									AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock)
{
	if(pRxBufBlock == nullptr || pTxBufBlock == nullptr)
		error_handler();

}

