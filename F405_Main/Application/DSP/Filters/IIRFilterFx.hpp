/*
 * IIRFilterFx.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#ifndef DSP_IIRFILTERFX_HPP_
#define DSP_IIRFILTERFX_HPP_

//#define ENABLE_IIR_BYPASS

#include <AbstractFx.hpp>



class IIRFilterFx : public AbstractFx
{
public:

	IIRFilterFx();

	#ifndef ENABLE_IIR_BYPASS
		void process_half_u16(	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
								StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf) override;
		void process_full_u16(	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
								StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf) override;
		void process_all_u16(	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
								StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf) override;
	#endif

private:

	arm_biquad_casd_df1_inst_f32 left_iir_settings, right_iir_settings;

	IIRState<4> iir_left_state{};
	IIRState<4> iir_right_state{};

	//IIR low-pass, fs=48kHz, f_cut=1kHz, q=0.707
	IIRCoeffSet<5> iir_coeffs = {
		0.003916123487156427f,
		0.007832246974312854f,
		0.003916123487156427f,
		1.8153396116625289f,
		-0.8310041056111546
	};

	static const uint16_t QTR_BLK_SIZE_F32 = 512;
	static const uint16_t HALF_BLK_SIZE_F32 = (QTR_BLK_SIZE_F32 * 2);

	MonoBlockF32 <IIRFilterFx::HALF_BLK_SIZE_F32> left_buf_in{};
	MonoBlockF32 <IIRFilterFx::HALF_BLK_SIZE_F32> right_buf_in{};
	MonoBlockF32 <IIRFilterFx::HALF_BLK_SIZE_F32> left_buf_out{};
	MonoBlockF32 <IIRFilterFx::HALF_BLK_SIZE_F32> right_buf_out{};

	int offset_read_ptr;
	int offset_write_ptr, write_ptr;

};




#endif /* DSP_IIRFILTERFX_HPP_ */