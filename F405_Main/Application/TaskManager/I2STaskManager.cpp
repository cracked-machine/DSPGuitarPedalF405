/*
 * I2STaskManager.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: chris
 */

#include <I2STaskManager.hpp>

#include <DSPManager.hpp>

#ifdef ENABLE_CCPUTESTS
#include <i2s.h>
#endif

#ifdef USE_FREERTOS

#else
	I2STskManNoRTOS::I2STskManNoRTOS()
	{


		//setDspManager(new(std::nothrow)  DSPManager());
	}

	I2STskManNoRTOS::~I2STskManNoRTOS()
	{

	}

	void I2STskManNoRTOS::nonRtosStateTask()
	{


		StateMachine *tmpMachine = this->getStateMachine();
		DSPManager* tmpDspMan = this->getDspManager();



		if(tmpMachine->getState() == tmpMachine->theStateList[StateMachine::FX_ENABLED])
		{
			// fixes the "random fx enable fail" bug but breaks the reverb effect
			//tmpDspMan->getFx()->zeroAllBuffers();
			tmpDspMan->unmute();


		}

		if(tmpMachine->getState() == tmpMachine->theStateList[StateMachine::FX_DISABLED])
		{
			tmpDspMan->mute();


		}

	}

	void I2STskManNoRTOS::nonRtosDspTask()
	{
		if	((this->getDspManager() != nullptr) &&
			(this->getDspManager()->getFx() != nullptr))
		{
			switch(this->getCallbackStatus())
			{
				case CallbackStatus_t::Half:

					switch(this->getDspManager()->getSampleMode())
					{
						case DSPManager::BLOCK_SAMPLE_MODE:
							this->getDspManager()->getFx()->process_half_u16_block(
									&this->getDspManager()->rxBufBlock,
									&this->getDspManager()->txBufBlock);
							break;

						case DSPManager::SINGLE_SAMPLE_MODE:
							this->getDspManager()->getFx()->process_half_u16_single(
									&this->getDspManager()->rxBufSingle,
									&this->getDspManager()->txBufSingle);
							break;

						case DSPManager::MUTE_MODE:
							break;
					}



					this->setCallbackStatus(CallbackStatus_t::Idle);
					break;

				case CallbackStatus_t::Full:

					switch(this->getDspManager()->getSampleMode())
					{
						case DSPManager::BLOCK_SAMPLE_MODE:
							this->getDspManager()->getFx()->process_full_u16_block(
									&this->getDspManager()->rxBufBlock,
									&this->getDspManager()->txBufBlock);
							break;

						case DSPManager::SINGLE_SAMPLE_MODE:
							this->getDspManager()->getFx()->process_full_u16_single(
									&this->getDspManager()->rxBufSingle,
									&this->getDspManager()->txBufSingle);

							break;

						case DSPManager::MUTE_MODE:
							break;
					}


					this->setCallbackStatus(CallbackStatus_t::Idle);
					break;

				default:
					break;

			}
		}
	}

	void I2STskManNoRTOS::setCallbackStatus(CallbackStatus_t pStatus)
	{
		if(	pStatus == CallbackStatus_t::Idle ||
			pStatus == CallbackStatus_t::Half ||
			pStatus == CallbackStatus_t::Full
		)
		{
			callbackStatus = pStatus;
		}
	}

	I2STskManNoRTOS::CallbackStatus_t I2STskManNoRTOS::getCallbackStatus()
	{
		return callbackStatus;
	}

#endif

