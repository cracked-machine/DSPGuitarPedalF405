/*
 * ISRTaskManager.hpp
 *
 *  Created on: Apr 14, 2021
 *      Author: chris
 */

#ifndef FREERTOS_ISRTASKMANAGER_HPP_
#define FREERTOS_ISRTASKMANAGER_HPP_

// FreeRTOS
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "EventMachine.hpp"



class ISRTaskManager
{

public:
	ISRTaskManager();

	void initEventMachine();
	void initIsrTask();
	void initIsrQueue();

	EventMachine* getIsrEventMan();
	TaskHandle_t getIsrTask();
	QueueHandle_t getQueue();

	void ISRQueueSendFromISR_wrapper(uint16_t item);

private:
	// static RTOS task
	TaskHandle_t ISRTaskHandle;
	StaticTask_t ISRTaskBuffer;
	StackType_t ISRTaskStack[ 200 ];

	// static RTOS queue for ISR-to-task comm
	uint8_t ISRQueueStorageArea[ 1 * sizeof( uint16_t ) ];
	QueueHandle_t ISRQueue;

	// create state machine instance
	EventMachine *ISREventMan;

};

#endif /* FREERTOS_ISRTASKMANAGER_HPP_ */
