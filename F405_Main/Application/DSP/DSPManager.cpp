/*
 * DSPManager.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */

#include <DSPManager.hpp>

#ifndef ENABLE_CPPUTEST
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_i2s_ex.h>
#include <i2s.h>
#endif

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



	// set the fx type
	//this->setFx(newFx);
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


void DSPManager::bringUp()
{
	// Test Schroeder reverb
	this->setSampleMode(SINGLE_SAMPLE_MODE);
	BasicReverb *newFx = new(std::nothrow) BasicReverb();
	// set the fx type
	this->setFx(newFx);
}

void DSPManager::tearDown()
{
	// Test Schroeder reverb
	this->setSampleMode(SINGLE_SAMPLE_MODE);
	AbstractFx* old = getFx();
	delete old;
	old = nullptr;

	BasicReverb *newFx = new(std::nothrow) BasicReverb();
	// set the fx type
	this->setFx(newFx);
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



void DSPManager::enable()
{
#ifndef ENABLE_CPPUTEST
	HAL_StatusTypeDef res = HAL_OK;

	switch(this->getSampleMode())
	{
		case DSPManager::BLOCK_SAMPLE_MODE:
			 res = HAL_I2SEx_TransmitReceive_DMA (	&hi2s2,
													txBufBlock.data(),
													rxBufBlock.data(),
													AbstractFx::STEREO_SINGLE_BLK_SIZE_U16);


			break;
		case DSPManager::SINGLE_SAMPLE_MODE:
			 res = HAL_I2SEx_TransmitReceive_DMA (	&hi2s2,
													txBufSingle.data(),
													rxBufSingle.data(),
													AbstractFx::STEREO_SINGLE_CH_SIZE_U16);


			break;

		default:
			 res = HAL_I2SEx_TransmitReceive_DMA (	&hi2s2,
													txBufSingle.data(),
													rxBufSingle.data(),
													AbstractFx::STEREO_SINGLE_CH_SIZE_U16);
	}

	if (res != HAL_OK)
		Error_Handler();
#endif
}

void DSPManager::disable()
{
#ifndef ENABLE_CPPUTEST
	HAL_StatusTypeDef res = HAL_OK;

	HAL_I2S_DMAStop(&hi2s2);

	if (res != HAL_OK)
		Error_Handler();
#endif
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
