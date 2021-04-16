/*
 * ExtCtrlTaskManager.hpp
 *
 *  Created on: Apr 14, 2021
 *      Author: chris
 */

#ifndef FREERTOS_EXTCTRLTASKMANAGER_HPP_
#define FREERTOS_EXTCTRLTASKMANAGER_HPP_

// FreeRTOS
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "EventMachine.hpp"

class ExtCtrlTaskManager
{

public:
	ExtCtrlTaskManager();

	void initEventMachine();
	void initTask();
	void initQueue();

	EventMachine* getEventMan();
	TaskHandle_t getTask();
	QueueHandle_t getQueue();


	void ExtCtrlQueueSendFromISR_wrapper(uint16_t item);

private:
	// static RTOS task
	TaskHandle_t ExtCtrlTaskHandle;
	StaticTask_t ExtCtrlTaskBuffer;
	StackType_t ExtCtrlTaskStack[ 200 ];

	// static RTOS queue for ISR-to-task comm
	uint8_t ExtCtrlQueueStorageArea[ 1 * sizeof( uint16_t ) ];
	QueueHandle_t ExtCtrlQueue;

	// create state machine instance
	EventMachine *ExtCtrlEventMan;

};

#endif /* FREERTOS_EXTCTRLTASKMANAGER_HPP_ */
