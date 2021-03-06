/*
 * IIRFilterFx.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#include <IIRFilterFx.hpp>


IIRFilterFx::IIRFilterFx()
{
#ifndef ENABLE_CPPUTEST
	  arm_biquad_cascade_df1_init_f32 ( &left_iir_settings, 1,
			  	  	  	  	  	  	  (float*)iir_coeffs.data(),
									  (float*)iir_left_state.data());
	  arm_biquad_cascade_df1_init_f32 ( &right_iir_settings, 1,
			  	  	  	  	  	  	  (float*)iir_coeffs.data(),
									  (float*)iir_right_state.data());
#endif
}

#ifndef ENABLE_IIR_BYPASS

	void IIRFilterFx::process_half_u16_block(	AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
												AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock)
	{
		if(pRxBufBlock != nullptr || pTxBufBlock != nullptr)
		{

		  offset_read_ptr = 0;
		  offset_write_ptr = 0;
		  write_ptr = 0;

		  process_all_u16_block(pRxBufBlock, pTxBufBlock);
		}
	}

	void IIRFilterFx::process_full_u16_block(	AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
												AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock)
	{
		if(pRxBufBlock != nullptr || pTxBufBlock != nullptr)
		{

			offset_read_ptr = STEREO_SINGLE_BLK_SIZE_U16;
			offset_write_ptr = IIRFilterFx::MONO_SINGLE_BLK_SIZE_F32;
			write_ptr = IIRFilterFx::MONO_SINGLE_BLK_SIZE_F32;

			process_all_u16_block(pRxBufBlock, pTxBufBlock);
		}
	}

	void IIRFilterFx::process_all_u16_block(	AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
												AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock)
	{
		if(pRxBufBlock != nullptr || pTxBufBlock != nullptr)
		{

		  //restore input sample buffer to float array
		  for (size_t i = offset_read_ptr; i  <offset_read_ptr + STEREO_SINGLE_BLK_SIZE_U16; i = i + 4) {
			  left_buf_in[write_ptr] = (float)((int) ((*pRxBufBlock)[i] << 16 ) 	| ( *pRxBufBlock)[i+1] );
			  right_buf_in[write_ptr] = (float)((int) ((*pRxBufBlock)[i+2] << 16 ) 	| ( *pRxBufBlock)[i+3] );
			  write_ptr++;
		  }


		#ifndef ENABLE_CPPUTEST
		  //process IIR
		  arm_biquad_cascade_df1_f32 (&left_iir_settings, &left_buf_in[offset_write_ptr], &left_buf_out[offset_write_ptr], IIRFilterFx::MONO_SINGLE_BLK_SIZE_F32);
		  arm_biquad_cascade_df1_f32 (&right_iir_settings, &right_buf_in[offset_write_ptr], &right_buf_out[offset_write_ptr], IIRFilterFx::MONO_SINGLE_BLK_SIZE_F32);
		#endif

		  //restore processed float-array to output sample-buffer
		  write_ptr = offset_write_ptr;

		  for (size_t i = offset_read_ptr; i  <offset_read_ptr + STEREO_SINGLE_BLK_SIZE_U16; i = i + 4) {
				(*pTxBufBlock)[i] =  	( ((int)left_buf_out[write_ptr]) >> 16 ) & 0xFFFF;
				(*pTxBufBlock)[i+1] = 	( (int)left_buf_out[write_ptr] ) & 0xFFFF;
				(*pTxBufBlock)[i+2] = 	( ((int)left_buf_out[write_ptr] ) >> 16 ) & 0xFFFF;
				(*pTxBufBlock)[i+3] = 	( (int)left_buf_out[write_ptr] ) & 0xFFFF;
				write_ptr++;
		  }
		}

	}




#endif

