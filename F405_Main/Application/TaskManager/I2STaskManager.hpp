/*
 * I2STaskManager.hpp
 *
 *  Created on: Apr 21, 2021
 *      Author: chris
 */

#ifndef TASKMANAGER_I2STASKMANAGER_HPP_
#define TASKMANAGER_I2STASKMANAGER_HPP_

#include <BaseTaskManager.hpp>

#ifdef USE_FREERTOS

	typedef BaseTaskManager<uint8_t, StateMachine> I2STaskManager_t;

#else

	typedef BaseTaskManager<uint8_t, StateMachine> I2STaskManager_t;


	class I2STskManNoRTOS : public I2STaskManager_t
	{
	public:
		I2STskManNoRTOS();
		~I2STskManNoRTOS();

		/*
		 * check there is system memory available before allocation or return nullptr
		 */
		void* operator new(size_t size, const std::nothrow_t& tag) noexcept {
				if(ResourceManager::checkSystemMem< I2STskManNoRTOS >(size))
					return malloc(size);
				else
					return nullptr;
		}

		void nonRtosStateTask();
		void nonRtosDspTask();

		enum CallbackStatus_t
		{
			Idle = 0,
			Half,
			Full
		};

		void setCallbackStatus(I2STskManNoRTOS::CallbackStatus_t pStatus);
		I2STskManNoRTOS::CallbackStatus_t getCallbackStatus();

	private:

		CallbackStatus_t callbackStatus = I2STskManNoRTOS::Idle;

	};
#endif



#endif /* TASKMANAGER_I2STASKMANAGER_HPP_ */
