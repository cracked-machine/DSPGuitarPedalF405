/*
 * AbstractFx.cpp
 *
 *  Created on: Apr 18, 2021
 *      Author: chris
 */


#include <AbstractFx.hpp>


AbstractFx::AbstractFx()
{

}

AbstractFx::~AbstractFx()
{

}


void AbstractFx::process_half_u16_single(AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pRxBufSingle,
										 AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pTxBufSingle)
{
	if(pRxBufSingle != nullptr  || pTxBufSingle != nullptr)
	{
		// do something for first half samples here if needed
		for(size_t i = 0; i < STEREO_SINGLE_CH_SIZE_U16; i++ )
		{
			(*pTxBufSingle)[i] = (*pRxBufSingle)[i];
		}
	}

}


void AbstractFx::process_full_u16_single(AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pRxBufSingle,
										 AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pTxBufSingle)
{
	if(pRxBufSingle != nullptr  || pTxBufSingle != nullptr)
	{
		// do something for second half samples here if needed
		for(size_t i = STEREO_SINGLE_CH_SIZE_U16; i < STEREO_DOUBLE_CH_SIZE_U16; i++ )
		{
			(*pTxBufSingle)[i] = (*pRxBufSingle)[i];
		}
	}
}

void AbstractFx::process_all_u16_single(AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pRxBufSingle,
										AudioBlockU16< STEREO_DOUBLE_CH_SIZE_U16 > *pTxBufSingle)
{
	// do default for all samples here if needed
}

void AbstractFx::process_mute()
{
	// do nothing
}

// default passthru implementation for first half of data
void AbstractFx::process_half_u16_block(AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
										AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock)
{
	if(pRxBufBlock != nullptr  || pTxBufBlock != nullptr)
	{
		// do something for first half samples here if needed
		for(size_t i = 0; i < STEREO_SINGLE_BLK_SIZE_U16; i++ )
		{
			(*pTxBufBlock)[i] = (*pRxBufBlock)[i];
		}
	}
}

// default passthru implementation for second half of data
void AbstractFx::process_full_u16_block(AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
										AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock)
{
	if(pRxBufBlock != nullptr  || pTxBufBlock != nullptr)
	{
		// do something for second half samples here if needed
		for(size_t i = STEREO_SINGLE_BLK_SIZE_U16; i < STEREO_DOUBLE_BLK_SIZE_U16; i++ )
		{
			(*pTxBufBlock)[i] = (*pRxBufBlock)[i];
		}
	}
}

void AbstractFx::process_all_u16_block(	AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pRxBufBlock,
										AudioBlockU16< STEREO_DOUBLE_BLK_SIZE_U16 > *pTxBufBlock)
{
	// do default for all samples here if needed
}

void AbstractFx::zeroAllBuffers()
{
	std::cout << "Call to base AbstractFx::zeroBuffer() method" << std::endl;
}

void AbstractFx::error_handler()
{

}
