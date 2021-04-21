/*
 * IIRFilterFx2.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#ifndef DSP_IIRFILTERFX_HPP_
#define DSP_IIRFILTERFX_HPP_

//#define ENABLE_IIR_BYPASS

#include <AbstractFx.hpp>
#include <iostream>
#include <ResourceManager.hpp>




class IIRFilterFx2 : public AbstractFx
{
public:

	IIRFilterFx2();

	#ifndef ENABLE_IIR_BYPASS
		void process_half_u16(	AudioBlockU16< FULL_BLK_SIZE_U16 > *pRxBuf,
								AudioBlockU16< FULL_BLK_SIZE_U16 > *pTxBuf) override;
		void process_full_u16(	AudioBlockU16< FULL_BLK_SIZE_U16 > *pRxBuf,
								AudioBlockU16< FULL_BLK_SIZE_U16 > *pTxBuf) override;
		void process_all_u16(	AudioBlockU16< FULL_BLK_SIZE_U16 > *pRxBuf,
								AudioBlockU16< FULL_BLK_SIZE_U16 > *pTxBuf) override;
	#endif

		/*
		 * check there is system memory available before allocation or return nullptr
		 */

		void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
				if(ResourceManager::checkSystemMem< IIRFilterFx2 >(size))
					return malloc(size);
				else
					return nullptr;
		}


private:

#ifndef ENABLE_CPPUTEST
	arm_biquad_casd_df1_inst_f32 left_iir_settings, right_iir_settings;
#endif
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



	AudioBlockF32 <STEREO_CH_SIZE_F32> left_buf_in{};
	AudioBlockF32 <STEREO_CH_SIZE_F32> right_buf_in{};
	AudioBlockF32 <STEREO_CH_SIZE_F32> left_buf_out{};
	AudioBlockF32 <STEREO_CH_SIZE_F32> right_buf_out{};

	int offset_read_ptr;
	int offset_write_ptr, write_ptr;

	AudioBlockF32< STEREO_CH_SIZE_F32 > pLeftIn;
	AudioBlockF32< STEREO_CH_SIZE_F32 > pRightIn;
	AudioBlockF32< STEREO_CH_SIZE_F32 > pLeftOut;
	AudioBlockF32< STEREO_CH_SIZE_F32 > pRightOut;

};




#endif /* DSP_IIRFILTERFX_HPP_ */