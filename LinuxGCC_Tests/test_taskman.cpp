/*
 * test_taskman.cpp
 *
 *  Created on: 19 Apr 2021
 *      Author: chris
 */




#include "CppUTest/TestHarness.h"
#include <BaseTaskManager.hpp>

#include <test_hal_testenv.h>

typedef BaseTaskManager<uint16_t, StateMachine> TestTaskManager_t;

// FreeRTOS stub functions

TaskHandle_t xTaskCreateStatic( TaskFunction_t pxTaskCode,
								const char * const pcName, /*lint !e971 Unqualified char types are allowed for strings and single characters only. */
								const uint32_t ulStackDepth,
								void * const pvParameters,
								UBaseType_t uxPriority,
								StackType_t * const puISRTaskStackBuffer,
								StaticTask_t * const pISRTaskBuffer )
{
	// we don't reach the function so we don't care if it returns null
	return nullptr;
}

QueueHandle_t ISRQueueGenericCreateStatic( const UBaseType_t uISRQueueLength,
                                          const UBaseType_t uxItemSize,
                                          uint8_t * pucQueueStorage,
                                          StaticQueue_t * pxStaticQueue,
                                          const uint8_t ucQueueType )
 {
	// we don't reach the function so we don't care if it returns null
	return nullptr;
 }

BaseType_t ISRQueueGenericSendFromISR( QueueHandle_t ISRQueue,
                                     const void * const pvItemToQueue,
                                     BaseType_t * const pxHigherPriorityTaskWoken,
                                     const BaseType_t xCopyPosition )
{
	// we don't reach the function so we don't care if it returns 0
	return 0;
}

// Tests

TEST_GROUP(TaskManGroup)
{
	void setup()
	{

	}

	void teardown()
	{

	}
};


TEST(TaskManGroup, TaskMan_ZeroTaskStackSizeTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t(0, 1);
	CHECK(taskman->getErrorStatus() == taskman->INVALID_STACK_QUEUE_SIZE_ERR);
	delete taskman;
}

TEST(TaskManGroup, TaskMan_ZeroQueueSizeTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t(200, 0);
	CHECK(taskman->getErrorStatus() == taskman->INVALID_STACK_QUEUE_SIZE_ERR);
	delete taskman;
}

TEST(TaskManGroup, TaskMan_ZeroQueueAndStackSizeTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t(0, 0);

	CHECK(taskman->getErrorStatus() == taskman->INVALID_STACK_QUEUE_SIZE_ERR);
	delete taskman;
}

TEST(TaskManGroup, TaskMan_SetTaskTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t(200, 1);
	taskman->setTask("", nullptr);
	CHECK(taskman->getErrorStatus() == taskman->NULL_TASK_PTR_ERR);
	delete taskman;
}

TEST(TaskManGroup, TaskMan_SetQueueTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t(200, 1);
	taskman->setQueue(nullptr);
	CHECK(taskman->getErrorStatus() == taskman->NULL_QUEUE_PTR_ERR);
	delete taskman;
}

TEST(TaskManGroup, TaskMan_SetStateMachineTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t(200, 1);
	taskman->setStateMachine(nullptr);
	CHECK(taskman->getErrorStatus() == taskman->NULL_STATEMACHINE_PTR_ERR);
	delete taskman;
}

TEST(TaskManGroup, TaskMan_QueueItemLowerBoundsTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t(200, 1);
	taskman->queueSendFromISR_wrapper(0);
	CHECK(taskman->getErrorStatus() == taskman->QUEUEITEM_OUTOFBOUNDS_ERR);
	delete taskman;
}

