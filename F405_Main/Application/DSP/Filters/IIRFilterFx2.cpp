/*
 * IIRFilterFx2.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#include <IIRFilterFx2.hpp>


IIRFilterFx2::IIRFilterFx2()
{
#ifndef ENABLE_CPPUTEST
	  arm_biquad_cascade_df1_init_f32 ( &left_iir_settings, 1, (float*)iir_coeffs.data(), (float*)iir_left_state.data());
	  arm_biquad_cascade_df1_init_f32 ( &right_iir_settings, 1, (float*)iir_coeffs.data(), (float*)iir_right_state.data());
#endif
}

#ifndef ENABLE_IIR_BYPASS
	void IIRFilterFx2::process_half_u16(	AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
											AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf)
	{
		if(pRxBuf == nullptr || pTxBuf == nullptr)
			error_handler();
/*
		// transfer single u16 sample
		AudioBlockU16< AbstractFx::HALF_BLK_SIZE_U16 > pRxBufTmp;
		AudioBlockU16< AbstractFx::HALF_BLK_SIZE_U16 > pTxBufTmp;
		// do something for first half samples here if needed
		for(size_t i = 0; i < HALF_BLK_SIZE_U16; i++ )
		{
			pRxBufTmp[i] = (*pRxBuf)[i];
			pTxBufTmp[i] = pRxBufTmp[i];
			(*pTxBuf)[i] = pTxBufTmp[i];
		}
*/
		// transfer blocks (HALF_BLK_SIZE_U16) u16 samples
/*
		AudioBlockU16< IIRFilterFx2::HALF_BLK_SIZE_U16 > pRxBufTmp;
		AudioBlockU16< IIRFilterFx2::HALF_BLK_SIZE_U16 > pTxBufTmp;

		// copy first half sample block from rx in buffer into tmp rx buffer
		for(size_t i = 0; i < HALF_BLK_SIZE_U16; i++ )
			pRxBufTmp[i] = (*pRxBuf)[i];
		// copy first half sample block into tmp tx buffer
		for(size_t i = 0; i < HALF_BLK_SIZE_U16; i++ )
			pTxBufTmp[i] = pRxBufTmp[i];
		// copy first half sample block into tx out buffer
		for(size_t i = 0; i < HALF_BLK_SIZE_U16; i++ )
			(*pTxBuf)[i] = pTxBufTmp[i];
*/

		// transfer (LEFT+RIGHT) F32 sample blocks

		// copy first half sample block from rx in buffer into tmp rx buffer
		for(size_t i = 0; i < HALF_BLK_SIZE_F32*2; i++ ) {
			pLeftIn[i] = (float) ((*pRxBuf)[i] << 16 | (*pRxBuf)[i+1]);
			pRightIn[i] = (float) ((*pRxBuf)[i+2] << 16 | (*pRxBuf)[i+3]);
		}
		// copy first half sample block into tmp tx buffer
		for(size_t i = 0; i < HALF_BLK_SIZE_F32*2; i++ ) {
			pLeftOut[i] = pLeftIn[i];
			pRightOut[i] = pRightIn[i];
		}
		// copy first half sample block into tx out buffer
		for(size_t i = 0; i < HALF_BLK_SIZE_F32*2; i++ )
		{
			(*pTxBuf)[i] 	=  ( ((int)pLeftOut[i]) >> 16 ) & 0xFFFF;
			(*pTxBuf)[i+1] 	=  ( ((int)pLeftOut[i]) & 0xFFFF );
			(*pTxBuf)[i+2] 	=  ( ((int)pRightOut[i]) >> 16 ) & 0xFFFF;
			(*pTxBuf)[i+3] 	=  ( ((int)pRightOut[i]) & 0xFFFF );
		}

	}

	void IIRFilterFx2::process_full_u16(	AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
											AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf)
	{
		if(pRxBuf == nullptr || pTxBuf == nullptr)
			error_handler();

		// transfer single u16 sample
/*		AudioBlockU16< AbstractFx::HALF_BLK_SIZE_U16 > pRxBufTmp;
		AudioBlockU16< AbstractFx::HALF_BLK_SIZE_U16 > pTxBufTmp;
		// do something for second half samples here if needed
		for(size_t i = HALF_BLK_SIZE_U16; i < FULL_BLK_SIZE_U16; i++ )
		{
			pRxBufTmp[i-HALF_BLK_SIZE_U16] = (*pRxBuf)[i];
			pTxBufTmp[i-HALF_BLK_SIZE_U16] = pRxBufTmp[i-HALF_BLK_SIZE_U16];
			(*pTxBuf)[i] = pTxBufTmp[i-HALF_BLK_SIZE_U16];
		}
*/
/*
		// transfer blocks (HALF_BLK_SIZE_U16) u16 samples
		AudioBlockU16< IIRFilterFx2::HALF_BLK_SIZE_U16 > pRxBufTmp;
		AudioBlockU16< IIRFilterFx2::HALF_BLK_SIZE_U16 > pTxBufTmp;

		// copy second half sample block from rx in buffer into tmp rx buffer
		for(size_t i = HALF_BLK_SIZE_U16; i < FULL_BLK_SIZE_U16; i++ )
			pRxBufTmp[i-HALF_BLK_SIZE_U16] = (*pRxBuf)[i];

		// copy second half sample block into tmp tx buffer
		for(size_t i = HALF_BLK_SIZE_U16; i < FULL_BLK_SIZE_U16; i++ )
			pTxBufTmp[i-HALF_BLK_SIZE_U16] = pRxBufTmp[i-HALF_BLK_SIZE_U16];

		// copy first half sample block into tx out buffer
		for(size_t i = HALF_BLK_SIZE_U16; i < FULL_BLK_SIZE_U16; i++ )
			(*pTxBuf)[i] = pTxBufTmp[i-HALF_BLK_SIZE_U16];
*/

		// transfer (LEFT+RIGHT) F32 sample blocks
/*
		// copy first half sample block from rx in buffer into tmp rx buffer
		for(size_t i = 0; i < QTR_BLK_SIZE_F32; i++ ) {
			pLeftIn[i] = (float) ((*pRxBuf)[HALF_BLK_SIZE_U16 + i] << 16 | (*pRxBuf)[HALF_BLK_SIZE_U16 + i + 1]);
			pRightIn[i] = (float) ((*pRxBuf)[HALF_BLK_SIZE_U16 + i + 2] << 16 | (*pRxBuf)[HALF_BLK_SIZE_U16 + i + 3]);
		}
		// copy first half sample block into tmp tx buffer
		for(size_t i = 0; i < QTR_BLK_SIZE_F32; i++ ) {
			pLeftOut[i] = pLeftIn[i];
			pRightOut[i] = pRightIn[i];
		}
		// copy first half sample block into tx out buffer
		for(size_t i = 0; i < QTR_BLK_SIZE_F32; i++ )
		{
			(*pTxBuf)[HALF_BLK_SIZE_U16 + i] 	=  ( ((int)pLeftOut[i]) >> 16 ) & 0xFFFF;
			(*pTxBuf)[HALF_BLK_SIZE_U16 + i + 1] 	=  ( ((int)pLeftOut[i]) & 0xFFFF );
			(*pTxBuf)[HALF_BLK_SIZE_U16 + i + 2] 	=  ( ((int)pRightOut[i]) >> 16 ) & 0xFFFF;
			(*pTxBuf)[HALF_BLK_SIZE_U16 + i + 3] 	=  ( ((int)pRightOut[i]) & 0xFFFF );
		}
*/
	}

	void IIRFilterFx2::process_all_u16(	AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
										AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf)
	{
		if(pRxBuf == nullptr || pTxBuf == nullptr)
			error_handler();



	}




#endif

