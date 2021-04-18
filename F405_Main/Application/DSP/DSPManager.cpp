/*
 * DSPManager.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */


#include "DSPManager.hpp"

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