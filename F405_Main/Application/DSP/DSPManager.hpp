/*
 * DSPManager.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#ifdef USE_HAL_DRIVER
#include <IIRFilterFx.hpp>
#endif
#include <Reverb.hpp>

class DSPManager
{

public:
	DSPManager(AbstractFx* pFx);
	virtual ~DSPManager();

	void setFx(AbstractFx* pFx);
	AbstractFx* getFx();

	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > rxBuf{};
	StereoBlockU16< AbstractFx::FULL_BLK_SIZE_U16 > txBuf{};
private:
	AbstractFx* theFx;


};


