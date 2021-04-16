/*
 * I2STaskManager.hpp
 *
 *  Created on: Apr 15, 2021
 *      Author: chris
 */

#ifndef FREERTOS_I2STASKMANAGER_HPP_
#define FREERTOS_I2STASKMANAGER_HPP_

// FreeRTOS
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"




class I2STaskManager
{
public:
	I2STaskManager();

	void initTask();
	void initQueue();

	TaskHandle_t getTask();
	QueueHandle_t getQueue();

	void queueSendFromISR_wrapper(uint8_t item);

private:
	// static RTOS task
	TaskHandle_t I2STaskHandle;
	StaticTask_t I2STaskBuffer;
	StackType_t I2STaskStack[ 200 ];

	// static RTOS queue for ISR-to-task comm
	uint8_t I2SQueueStorageArea[ 1 * sizeof( uint16_t ) ];
	QueueHandle_t I2SQueue;

};


#endif /* FREERTOS_I2STASKMANAGER_HPP_ */
