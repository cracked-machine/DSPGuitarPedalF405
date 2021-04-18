/*
 * BaseTaskManager.hpp
 *
 *  Created on: Apr 16, 2021
 *      Author: chris
 */

#ifndef FREERTOS_BASETASKMANAGER_HPP_
#define FREERTOS_BASETASKMANAGER_HPP_

// FreeRTOS
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <array>

#include "StateMachine.hpp"

//
// function pointer of task, to be passed as argument to BaseTaskManager::initTask
typedef void (*AbstractTaskPtr_t)(void*);



template<class T, class stateMachineType>
class BaseTaskManager
{
public:
	BaseTaskManager(size_t stackSize, size_t queueSize)
	{
		theTaskHandle = NULL;
		theTaskBuffer = {0};
		theTaskStack = NULL;
		theTaskStack = new StackType_t[stackSize];
		theQueueStorageArea = new uint8_t[ queueSize * sizeof( T ) ];
	}

	void initTask(		const char* _taskname,
						AbstractTaskPtr_t taskptr);

	void initQueue(StaticQueue_t *_staticQueue);

	void initStateMachine(StateMachine *pMachine);
	//void initStateMachine(AbstractStateContainer *pStates);

	TaskHandle_t getTask();
	QueueHandle_t getQueue();
	stateMachineType* getStateMachine();

	void queueSendFromISR_wrapper(T item);

private:


	TaskHandle_t theTaskHandle;
	StaticTask_t theTaskBuffer;
	StackType_t *theTaskStack;


	uint8_t *theQueueStorageArea;
	QueueHandle_t theQueue;

	// state machine instance
	stateMachineType *theStateMachine;

};

template<class T, class stateMachineType>
void BaseTaskManager<T, stateMachineType>::initTask(	const char* _taskname,
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

template<class T, class stateMachineType>
void BaseTaskManager<T, stateMachineType>::initQueue(StaticQueue_t *_staticQueue)
{
	// Create a queue capable of containing 10 uint64_t values.
	theQueue = ISRQueueCreateStatic(
		1,						// QUEUE_SIZE
		sizeof(T),		// ITEM_SIZE
		theQueueStorageArea,	// total queue storage size (QUEUE_SIZE * ITEM_SIZE)
		_staticQueue );		// Queue data structure
}

template<class T, class stateMachineType>
void BaseTaskManager<T, stateMachineType>::initStateMachine(StateMachine *pMachine)
//void BaseTaskManager<T>::initStateMachine(AbstractStateContainer *pStates)
{
	theStateMachine = pMachine;
}

template<class T, class stateMachineType>
TaskHandle_t BaseTaskManager<T, stateMachineType>::getTask()
{
	return this->theTaskHandle;
}

template<class T, class stateMachineType>
QueueHandle_t BaseTaskManager<T, stateMachineType>::getQueue()
{
	return this->theQueue;
}

template<class T, class stateMachineType>
stateMachineType* BaseTaskManager<T, stateMachineType>::getStateMachine()
{
	return this->theStateMachine;
}

template<class T, class stateMachineType>
void BaseTaskManager<T, stateMachineType>::queueSendFromISR_wrapper(T item)
{
	//ISRQueueSendFromISR(theQueue, &item, NULL);
	ISRQueueOverwriteFromISR(theQueue, &item, NULL);
}


// BaseTaskManager template specializations
typedef BaseTaskManager<uint8_t, StateMachine> I2STaskManager_t;
typedef BaseTaskManager<uint16_t, StateMachine> ExtCtrlTaskManager_t;


#endif /* FREERTOS_BASETASKMANAGER_HPP_ */
