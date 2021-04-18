/*
 * IIRFilterFx.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#ifndef DSP_FIRFILTERFX_HPP_
#define DSP_FIRFILTERFX_HPP_


#include "AbstractFx.hpp"

class FIRFilterFx : public AbstractFx
{
public:
	void process_half_u16(	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
							StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf) override;
	void process_full_u16(	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
							StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf) override;


};


#endif /* DSP_FIRFILTERFX_HPP_ */
