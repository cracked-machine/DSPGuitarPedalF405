/*
 * ExtCtrlTaskManager.cpp
 *
 *  Created on: Apr 21, 2021
 *      Author: chris
 */

#include <ExtCtrlTaskManager.hpp>

#ifdef USE_FREERTOS

#else

		ExtCtrlTaskManagerNoRTOS::ExtCtrlTaskManagerNoRTOS()
		{

		}

		ExtCtrlTaskManagerNoRTOS::~ExtCtrlTaskManagerNoRTOS()
		{

		}

		void ExtCtrlTaskManagerNoRTOS::nonRtosTask(uint16_t pData)
		{
			switch(pData)
			{
				case EXTI_PR_PR13:
					if(this->getStateMachine() != nullptr)
						this->getStateMachine()->evFootswitchA();
					break;
				case EXTI_PR_PR14:
					if(this->getStateMachine() != nullptr)
						this->getStateMachine()->evFootswitchB();
					break;
			}
		}

#endif


