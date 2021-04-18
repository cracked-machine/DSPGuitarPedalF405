/*
 * IIRFilterFx.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#ifndef DSP_IIRFILTERFX_HPP_
#define DSP_IIRFILTERFX_HPP_

//#define ENABLE_IIR_BYPASS

#include "AbstractFx.hpp"



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

	arm_biquad_casd_df1_inst_f32 iirsettings_l, iirsettings_r;

	std::array<float, 4> iir_l_state{};
	std::array<float, 4> iir_r_state{};

	//IIR low-pass, fs=48kHz, f_cut=1kHz, q=0.707
	std::array<float,5> iir_coeffs = {
		0.003916123487156427f,
		0.007832246974312854f,
		0.003916123487156427f,
		1.8153396116625289f,
		-0.8310041056111546
	};

	static const uint16_t IIR_BLOCK_SIZE_FLOAT = 512;

	std::array<float, IIRFilterFx::IIR_BLOCK_SIZE_FLOAT * 2> l_buf_in{};

	std::array<float, IIRFilterFx::IIR_BLOCK_SIZE_FLOAT * 2> r_buf_in{};
	std::array<float, IIRFilterFx::IIR_BLOCK_SIZE_FLOAT * 2> l_buf_out{};
	std::array<float, IIRFilterFx::IIR_BLOCK_SIZE_FLOAT * 2> r_buf_out{};

	int offset_r_ptr;
	int offset_w_ptr, w_ptr;

};




#endif /* DSP_IIRFILTERFX_HPP_ */
