/*
 * AbstractTaskManager.hpp
 *
 *  Created on: Apr 16, 2021
 *      Author: chris
 */

#ifndef FREERTOS_ABSTRACTTASKMANAGER_HPP_
#define FREERTOS_ABSTRACTTASKMANAGER_HPP_

// FreeRTOS
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <EventMachine.hpp>

// the typedef for global function to be used by FreeRTOS task member
// passed as argument to AbstractTaskManager::initTask
typedef void (*AbstractTaskPtr_t)(void*);



template<class T>
class AbstractTaskManager
{
public:
	AbstractTaskManager(size_t stackSize, size_t queueSize)
	{
		theTaskHandle = NULL;
		theTaskBuffer = {0};
		theTaskStack = NULL;
		theTaskStack = new StackType_t[200];
		theQueueStorageArea = new uint8_t[ queueSize * sizeof( T ) ];
	}

	void initTask(		const char* _taskname,
						AbstractTaskPtr_t taskptr);

	void initQueue(StaticQueue_t *_staticQueue);
	void initStateMachine();

	TaskHandle_t getTask();
	QueueHandle_t getQueue();
	EventMachine* getStateMachine();

	void queueSendFromISR_wrapper(T item);

private:
	// static RTOS task

	TaskHandle_t theTaskHandle;
	StaticTask_t theTaskBuffer;
	StackType_t *theTaskStack;

	// static RTOS queue for ISR-to-task comm
	uint8_t *theQueueStorageArea;
	QueueHandle_t theQueue;

	// state machine instance
	EventMachine *theStateMachine;
};

template<class T>
void AbstractTaskManager<T>::initTask(	const char* _taskname,
										AbstractTaskPtr_t taskptr)
{
	// Create the task without using any dynamic memory allocation.
	theTaskHandle = xTaskCreateStatic(
		taskptr,       		// global function in ExtCtrlTaskManager
		_taskname,          	// Text name for the task.
		200,      				// Number of indexes in the ISRTaskStack array.
		this,    				// pointer to this class instance (used by "IRSTaskMan" to access class members)
		tskIDLE_PRIORITY,		// Priority at which the task is created.
		theTaskStack,           // Array to use as the task's stack.
		&theTaskBuffer );  		// Variable to hold the task's data structure.
}

template<class T>
void AbstractTaskManager<T>::initQueue(StaticQueue_t *_staticQueue)
{
	/* Create a queue capable of containing 10 uint64_t values. */
	theQueue = ISRQueueCreateStatic(
		1,						// QUEUE_SIZE
		sizeof(T),		// ITEM_SIZE
		theQueueStorageArea,	// total queue storage size (QUEUE_SIZE * ITEM_SIZE)
		_staticQueue );		// Queue data structure
}

template<class T>
void AbstractTaskManager<T>::initStateMachine()
{
	theStateMachine = new EventMachine();
}

template<class T>
TaskHandle_t AbstractTaskManager<T>::getTask()
{
	return this->theTaskHandle;
}

template<class T>
QueueHandle_t AbstractTaskManager<T>::getQueue()
{
	return this->theQueue;
}

template<class T>
EventMachine* AbstractTaskManager<T>::getStateMachine()
{
	return this->theStateMachine;
}

template<class T>
void AbstractTaskManager<T>::queueSendFromISR_wrapper(T item)
{
	//ISRQueueSendFromISR(theQueue, &item, NULL);
	ISRQueueOverwriteFromISR(theQueue, &item, NULL);
}


// AbstractTaskManager template specializations
typedef AbstractTaskManager<uint8_t> I2STaskManager_t;
typedef AbstractTaskManager<uint16_t> ExtCtrlTaskManager_t;


#endif /* FREERTOS_ABSTRACTTASKMANAGER_HPP_ */