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

DSPManager::SampleMode DSPManager::theSampleMode = BLOCK_SAMPLE_MODE;
DSPManager::SampleMode DSPManager::theSavedMode = BLOCK_SAMPLE_MODE;


DSPManager::DSPManager()
{
	// Test CMSIS IIR Filter
	//this->setSampleMode(BLOCK_SAMPLE_MODE);
	//IIRFilterFx *newFx = new(std::nothrow) IIRFilterFx();

	// Test Schroeder reverb
	this->setSampleMode(SINGLE_SAMPLE_MODE);
	BasicReverb *newFx = new(std::nothrow) BasicReverb();

	// set the fx type
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

void DSPManager::setSampleMode(DSPManager::SampleMode pMode)
{
	if(	pMode == DSPManager::BLOCK_SAMPLE_MODE ||
		pMode == DSPManager::SINGLE_SAMPLE_MODE
	)
	{
		theSampleMode = pMode;
	}

}

DSPManager::SampleMode DSPManager::getSampleMode()
{
	return theSampleMode;
}

void DSPManager::mute()
{
	if(theSampleMode != MUTE_MODE)
	{
		// save the current sample mode so we can return to it later
		theSavedMode = theSampleMode;

		// mute the DSPManager output
		theSampleMode = MUTE_MODE;


	}
}

void DSPManager::unmute()
{
	// return to the sample mode used before DSPManager was muted.
	if(theSampleMode == MUTE_MODE)
	{
		theSampleMode = theSavedMode;
	}

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
