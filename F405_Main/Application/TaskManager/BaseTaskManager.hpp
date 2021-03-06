/*
 * BaseTaskManager.hpp
 *
 *  Created on: Apr 16, 2021
 *      Author: chris
 */

#ifndef FREERTOS_BASETASKMANAGER_HPP_
#define FREERTOS_BASETASKMANAGER_HPP_


#include <StateMachine.hpp>
#include <ResourceManager.hpp>

class DSPManager;

// FreeRTOS
//#include "FreeRTOS.h"
//#include "task.h"
//#include "queue.h"


#include <array>

#ifndef DISABLE_ERROR_HANDLER
	#define FOREVER 1
#else
	#define FOREVER 0
#endif

//
// function pointer of task, to be passed as argument to BaseTaskManager::setTask
typedef void (*AbstractTaskPtr_t)(void*);



template<class T, class stateMachineType>
class BaseTaskManager
{
public:
	BaseTaskManager()
	{
		theStateMachine = nullptr;
		theDspMan = nullptr;
	}

	#ifdef USE_FREERTOS
		BaseTaskManager(size_t pStackSize, size_t pQueueSize)
		{
			theTaskHandle = nullptr;
			theTaskBuffer = {0};
			theTaskStack = nullptr;
			theQueueStorageArea = 0;
			theQueue = {0};
			theStateMachine = nullptr;
			theDspMan = nullptr;

			if(pStackSize == 0 || pQueueSize == 0)
			{

				error_handler(INVALID_STACK_QUEUE_SIZE_ERR);
			}
			else
			{
				theTaskStack = new  StackType_t[pStackSize];
				theQueueStorageArea = new  uint8_t[ pQueueSize * sizeof( T ) ];
			}

		}
	#else

	#endif




	~BaseTaskManager()
	{
		#ifdef USE_FREERTOS
				delete[] theTaskStack;
				delete[] theQueueStorageArea;
		#endif
	}

	#ifdef USE_FREERTOS
		void setTask(		const char* pTaskName,
							AbstractTaskPtr_t pTaskPtr);
		void setQueue(StaticQueue_t *pStaticQueue);
		TaskHandle_t getTask();
		QueueHandle_t getQueue();
		void queueSendFromISR_wrapper(T item);
	#else
		//void nonRtosTask();
	#endif


	void setStateMachine(StateMachine *pMachine);
	stateMachineType* getStateMachine();

	DSPManager *getDspManager();
	void setDspManager(DSPManager *pDspMan);


/*

	enum taskFatalErrTypes
	{
		STATUS_OK = 0,
		INVALID_STACK_QUEUE_SIZE_ERR,
		INVALID_DSP_MANAGER,
		NULL_TASK_PTR_ERR,
		NULL_QUEUE_PTR_ERR,
		NULL_STATEMACHINE_PTR_ERR,
		QUEUEITEM_OUTOFBOUNDS_ERR
	};

	int getErrorStatus();

*/

private:

	#ifdef USE_FREERTOS
		TaskHandle_t theTaskHandle;
		StaticTask_t theTaskBuffer;
		StackType_t *theTaskStack;


		uint8_t *theQueueStorageArea;
		QueueHandle_t theQueue;

	#else



	#endif

	// state machine instance
	stateMachineType *theStateMachine;

	DSPManager *theDspMan;

	//BaseTaskManager::taskFatalErrTypes status = STATUS_OK;
	//void error_handler(BaseTaskManager::taskFatalErrTypes pError);

};



template<class T, class stateMachineType>
DSPManager* BaseTaskManager<T, stateMachineType>::getDspManager()
{
	if(this->theDspMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< DSPManager >();
		return nullptr; // not reached
	}
	else
	{
		return theDspMan;
	}

}



#ifdef USE_FREERTOS

	template<class T, class stateMachineType>
	void BaseTaskManager<T, stateMachineType>::setTask(	const char* pTaskName,
											AbstractTaskPtr_t pTaskPtr)
	{
		if(pTaskPtr == nullptr)
		{
			error_handler(NULL_TASK_PTR_ERR);
		}
		else
		{
			// Create the task without using any dynamic memory allocation.
			theTaskHandle = xTaskCreateStatic(
				pTaskPtr,       		// global function in ExtCtrlTaskManager
				pTaskName,          	// Text name for the task.
				200,      				// Number of indexes in the ISRTaskStack array.
				this,    				// pointer to this class instance (used by "IRSTaskMan" to access class members)
				tskIDLE_PRIORITY,		// Priority at which the task is created.
				theTaskStack,           // Array to use as the task's stack.
				&theTaskBuffer );  		// Variable to hold the task's data structure.
		}
	}

	template<class T, class stateMachineType>
	void BaseTaskManager<T, stateMachineType>::setQueue(StaticQueue_t *pStaticQueue)
	{
		if(pStaticQueue == nullptr)
		{
			error_handler(NULL_QUEUE_PTR_ERR);
		}
		else
		{
			// Create a queue capable of containing 10 uint64_t values.
			theQueue = ISRQueueCreateStatic(
				1,						// QUEUE_SIZE
				sizeof(T),		// ITEM_SIZE
				theQueueStorageArea,	// total queue storage size (QUEUE_SIZE * ITEM_SIZE)
				pStaticQueue );		// Queue data structure
		}

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
	void BaseTaskManager<T, stateMachineType>::queueSendFromISR_wrapper(T item)
	{
		if(item < 1) { error_handler(QUEUEITEM_OUTOFBOUNDS_ERR); }
		else
		{
			//ISRQueueSendFromISR(theQueue, &item, NULL);
			ISRQueueOverwriteFromISR(theQueue, &item, NULL);
		}

	}

#else
/*
	template<class T, class stateMachineType>
	void BaseTaskManager<T, stateMachineType>::nonRtosTask()
	{

	}
*/
#endif

template<class T, class stateMachineType>
void BaseTaskManager<T, stateMachineType>::setDspManager(DSPManager *pDspMan)
{
	if(pDspMan == nullptr)
	{
		ResourceManager::notifySysNullPtr< DSPManager >();
	}
	else
	{
		theDspMan = pDspMan;
	}
}

template<class T, class stateMachineType>
void BaseTaskManager<T, stateMachineType>::setStateMachine(StateMachine *pMachine)
//void BaseTaskManager<T>::setStateMachine(AbstractStateContainer *pStates)
{
	if(pMachine == nullptr)
	{
		ResourceManager::notifySysNullPtr< StateMachine >();
	}
	else
	{
		theStateMachine = pMachine;
	}
}

template<class T, class stateMachineType>
stateMachineType* BaseTaskManager<T, stateMachineType>::getStateMachine()
{
	if(this->theStateMachine == nullptr)
	{
		ResourceManager::notifySysNullPtr< StateMachine >();
		return nullptr;
	}
	else
	{
		return this->theStateMachine;
	}

}

/*
template<class T, class stateMachineType>
int BaseTaskManager<T, stateMachineType>::getErrorStatus()
{
	return status;
}

template<class T, class stateMachineType>
void BaseTaskManager<T, stateMachineType>::error_handler(BaseTaskManager::taskFatalErrTypes pError)
{
	std::cout << "Caught error(" << pError << ") at BaseTaskManager::error_handler()" << std::endl;
	status = pError;
	while(FOREVER)
	{

	}
}
*/
// BaseTaskManager template specializations
//typedef BaseTaskManager<uint8_t, StateMachine> I2STaskManager_t;
//typedef BaseTaskManager<uint16_t, StateMachine> ExtCtrlTaskManager_t;


#endif /* FREERTOS_BASETASKMANAGER_HPP_ */
