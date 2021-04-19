/*
 * IIRFilterFx.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */




#include "FIRFilterFx.hpp"

void FIRFilterFx::process_half_u16(	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
									StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf)
{
	if(pRxBuf == nullptr || pTxBuf == nullptr)
		error_handler();

}

void FIRFilterFx::process_full_u16(	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
									StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf)
{
	if(pRxBuf == nullptr || pTxBuf == nullptr)
		error_handler();

}

