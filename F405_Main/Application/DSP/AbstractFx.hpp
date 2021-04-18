/*
 * AbstractFx.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#ifndef DSP_ABSTRACTFX_HPP_
#define DSP_ABSTRACTFX_HPP_

#define BLOCK_SIZE_U16 2048
#define STEREO_BLOCK_SIZE_U16 (BLOCK_SIZE_U16 * 2)

using namespace std;

#include "stdint.h"
#include <array>

#include "arm_math.h"

class AbstractFx
{

public:
	AbstractFx();
	virtual ~AbstractFx();


	virtual void process_half_u16(	array<uint16_t, STEREO_BLOCK_SIZE_U16> *pRxBuf,
									array<uint16_t, STEREO_BLOCK_SIZE_U16> *pTxBuf);

	virtual void process_full_u16(	array<uint16_t, STEREO_BLOCK_SIZE_U16> *pRxBuf,
									array<uint16_t, STEREO_BLOCK_SIZE_U16> *pTxBuf);

	virtual void process_all_u16(	array<uint16_t, STEREO_BLOCK_SIZE_U16> *pRxBuf,
									array<uint16_t, STEREO_BLOCK_SIZE_U16> *pTxBuf);


private:


};

#endif /* DSP_ABSTRACTFX_HPP_ */