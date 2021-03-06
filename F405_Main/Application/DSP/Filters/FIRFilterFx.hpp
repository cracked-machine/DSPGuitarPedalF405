/*
 * IIRFilterFx.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#ifndef DSP_FIRFILTERFX_HPP_
#define DSP_FIRFILTERFX_HPP_


#include <AbstractFx.hpp>

class FIRFilterFx : public AbstractFx
{
public:
	void process_half_u16_block(	AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
							AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock) override;
	void process_full_u16_block(	AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
							AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock) override;


};


#endif /* DSP_FIRFILTERFX_HPP_ */
