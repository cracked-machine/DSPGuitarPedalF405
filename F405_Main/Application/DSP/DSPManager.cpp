/*
 * DSPManager.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#include <DSPManager.hpp>

#include <IIRFilterFx.hpp>
//#include <IIRFilterFx2.hpp>
#include <Reverb.hpp>



DSPManager::DSPManager()
{

	//IIRFilterFx *newFx = new(std::nothrow) IIRFilterFx();
	BasicReverb *newFx = new(std::nothrow) BasicReverb();
	this->setFx(newFx);
}

DSPManager::DSPManager(AbstractFx* pFx)
{
	if(pFx != nullptr)
		theFx = pFx;
}

DSPManager::~DSPManager()
{
	delete theFx;
}

void DSPManager::setFx(AbstractFx* pFx)
{
	if(pFx != nullptr)
		theFx = pFx;
}

AbstractFx* DSPManager::getFx()
{
	return theFx;
}
