/*
 * IIRFilterFx.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#include "IIRFilterFx.hpp"


IIRFilterFx::IIRFilterFx()
{
	  arm_biquad_cascade_df1_init_f32 ( &iirsettings_l, 1, &iir_coeffs[0], &iir_l_state[0]);
	  arm_biquad_cascade_df1_init_f32 ( &iirsettings_r, 1, &iir_coeffs[0], &iir_r_state[0]);
}

#ifndef ENABLE_IIR_BYPASS
	void IIRFilterFx::process_half_u16(	array<uint16_t, STEREO_BLOCK_SIZE_U16> *pRxBuf,
										array<uint16_t, STEREO_BLOCK_SIZE_U16> *pTxBuf)
	{
		  offset_r_ptr = 0;
		  offset_w_ptr = 0;
		  w_ptr = 0;

		  process_all_u16(pRxBuf, pTxBuf);
	}

	void IIRFilterFx::process_full_u16(	array<uint16_t, STEREO_BLOCK_SIZE_U16> *pRxBuf,
										array<uint16_t, STEREO_BLOCK_SIZE_U16> *pTxBuf)
	{
		offset_r_ptr = BLOCK_SIZE_U16;
		offset_w_ptr = IIRFilterFx::IIR_BLOCK_SIZE_FLOAT;
		w_ptr = IIRFilterFx::IIR_BLOCK_SIZE_FLOAT;

		process_all_u16(pRxBuf, pTxBuf);
	}

	void IIRFilterFx::process_all_u16(	array<uint16_t, STEREO_BLOCK_SIZE_U16> *pRxBuf,
										array<uint16_t, STEREO_BLOCK_SIZE_U16> *pTxBuf)
	{
		  //restore input sample buffer to float array
		  for (int i=offset_r_ptr; i<offset_r_ptr+BLOCK_SIZE_U16; i=i+4) {
			  l_buf_in[w_ptr] = (float) ((int) ((*pRxBuf)[i]<<16)|(*pRxBuf)[i+1]);
			  r_buf_in[w_ptr] = (float) ((int) ((*pRxBuf)[i+2]<<16)|(*pRxBuf)[i+3]);
			  w_ptr++;
		  }


		  //process IIR
		  arm_biquad_cascade_df1_f32 (&iirsettings_l, &l_buf_in[offset_w_ptr], &l_buf_out[offset_w_ptr],IIRFilterFx::IIR_BLOCK_SIZE_FLOAT);
		  arm_biquad_cascade_df1_f32 (&iirsettings_r, &r_buf_in[offset_w_ptr], &r_buf_out[offset_w_ptr],IIRFilterFx::IIR_BLOCK_SIZE_FLOAT);


		  //restore processed float-array to output sample-buffer
		  w_ptr = offset_w_ptr;

		  for (int i=offset_r_ptr; i<offset_r_ptr+BLOCK_SIZE_U16; i=i+4) {
				(*pTxBuf)[i] =  (((int)l_buf_out[w_ptr])>>16)&0xFFFF;
				(*pTxBuf)[i+1] = ((int)l_buf_out[w_ptr])&0xFFFF;
				(*pTxBuf)[i+2] = (((int)l_buf_out[w_ptr])>>16)&0xFFFF;
				(*pTxBuf)[i+3] = ((int)l_buf_out[w_ptr])&0xFFFF;
				w_ptr++;
		  }

	}

#endif
