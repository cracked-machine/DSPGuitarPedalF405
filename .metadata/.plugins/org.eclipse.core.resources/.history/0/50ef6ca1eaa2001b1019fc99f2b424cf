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


#ifndef ENABLE_CPPUTEST
	#include "arm_math.h"
#endif

#include <BlockTypes.hpp>


class AbstractFx
{

public:
	AbstractFx();
	virtual ~AbstractFx();

	static const size_t HALF_BLK_SIZE_U16 = 2048;
	static const size_t FULL_BLK_SIZE_U16 = (AbstractFx::HALF_BLK_SIZE_U16 * 2);



	virtual void process_half_u16(	AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
									AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf);

	virtual void process_full_u16(	AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
									AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf);

	virtual void process_all_u16(	AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pRxBuf,
									AudioBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > *pTxBuf);

	void error_handler();
private:

};





#endif /* DSP_ABSTRACTFX_HPP_ */
