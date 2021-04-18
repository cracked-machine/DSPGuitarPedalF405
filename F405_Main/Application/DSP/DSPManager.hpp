/*
 * DSPManager.hpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#include "IIRFilterFx.hpp"





class DSPManager
{

public:
	DSPManager(AbstractFx* pFx);
	virtual ~DSPManager();

	void setFx(AbstractFx* pFx);
	AbstractFx* getFx();
private:
	AbstractFx* theFx;

};


