/*
 * AbstractFx.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#ifndef DSP_ABSTRACTFX_HPP_
#define DSP_ABSTRACTFX_HPP_


using namespace std;

#include "stdint.h"
#include <array>
#include <ResourceManager.hpp>


#ifndef ENABLE_CPPUTEST
	#include "arm_math.h"
#endif

#include <BlockTypes.hpp>
using namespace AudioBlockTypes;
using namespace FilterArrayTypes;

class AbstractFx
{

public:
	AbstractFx();
	virtual ~AbstractFx();


	// 1 x F32 per sample, Mono channel: 512 samples per block
	// Ch: F32 (first 24 data bits + 8 zero bits)
	static const size_t MONO_SINGLE_BLK_SIZE_F32 = 512;

	// 1 x F32 per sample, Stereo channel: 1024 samples per block
	// LCh: F32 (first 24 data bits + 8 zero bits)
	// RCh: F32 (first 24 data bits + 8 zero bits)
	static const size_t STEREO_SINGLE_BLK_SIZE_F32 = 1024;


	// 2 x U16 per sample, one buffer: 1024 samples per block
	// LCh: U16 (first 16 data bits)
	// LCh: U16 (last 8 data bits + 8 zero bits)
	// RCh: U16 (first 16 data bits)
	// RCh: U16 (last 8 data bits + 8 zero bits)
	static const size_t STEREO_SINGLE_BLK_SIZE_U16 = 2048;


	// 2 x U16 per sample, two buffers: 1024 samples per block.
	// LCh_BufA: U16 (first 16 data bits)
	// LCh_BufA: U16 (last 8 data bits + 8 zero bits)
	// RCh_BufA: U16 (first 16 data bits)
	// RCh_BUfA: U16 (last 8 data bits + 8 zero bits)
	// LCh_BufB: U16 (first 16 data bits)
	// LCh-BufB: U16 (last 8 data bits + 8 zero bits)
	// RCh_BufB: U16 (first 16 data bits)
	// RCh_BufB: U16 (last 8 data bits + 8 zero bits)
	static const size_t STEREO_DOUBLE_BLK_SIZE_U16 = 4096;


	// 2 x U16 per sample, stereo channel, one buffer: 2 samples in total
	// LCh_BufA: U16 (first 16 data bits)
	// LCh_BufA: U16 (last 8 data bits + 8 zero bits)
	// RCh_BufA: U16 (first 16 data bits)
	// RCh_BUfA: U16 (last 8 data bits + 8 zero bits)
	static const size_t STEREO_SINGLE_CH_SIZE_U16 = 4;

	// 2 x U16 per sample, stereo channel, two buffers: 4 samples in total
	// LCh_BufA: U16 (first 16 data bits)
	// LCh_BufA: U16 (last 8 data bits + 8 zero bits)
	// RCh_BufA: U16 (first 16 data bits)
	// RCh_BUfA: U16 (last 8 data bits + 8 zero bits)
	// LCh_BufB: U16 (first 16 data bits)
	// LCh-BufB: U16 (last 8 data bits + 8 zero bits)
	// RCh_BufB: U16 (first 16 data bits)
	// RCh_BufB: U16 (last 8 data bits + 8 zero bits)
	static const size_t STEREO_DOUBLE_CH_SIZE_U16 = 8;

	// 1 x F32 per sample, stereo channel, two buffers: 4 samples in total
	// LCh_BufA: F32 (first 24 data bits + 8 zero bits)
	// RCh_BufA: F32 (first 24 data bits + 8 zero bits)
	// LCh_BufB: F32 (first 24 data bits + 8 zero bits)
	// RCh_BufB: F32 (first 24 data bits + 8 zero bits)
	static const size_t STEREO_DOUBLE_CH_SIZE_F32 = 4;



	virtual void process_half_u16_block(AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
										AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock);

	virtual void process_full_u16_block(AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
										AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock);

	virtual void process_all_u16_block(	AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
										AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock);

	virtual void process_half_u16_single(AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pRxBufSingle,
										 AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pTxBufSingle);

	virtual void process_full_u16_single(AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pRxBufSingle,
										 AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pTxBufSingle);

	virtual void process_all_u16_single(AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pRxBufSingle,
										AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pTxBufSingle);

	virtual void process_mute();

	void zeroAllBuffers();


	void error_handler();
private:

};





#endif /* DSP_ABSTRACTFX_HPP_ */
