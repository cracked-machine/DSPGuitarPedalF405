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

TEST(TaskManGroup, TaskMan_SetDspManTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t();
	taskman->setDspManager(nullptr);
	//CHECK(taskman->getErrorStatus() == taskman->INVALID_DSP_MANAGER);
	delete taskman;
}
TEST(TaskManGroup, TaskMan_SetStateMachineTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t();
	taskman->setStateMachine(nullptr);
	//CHECK(taskman->getErrorStatus() == taskman->NULL_STATEMACHINE_PTR_ERR);
	delete taskman;
}

// These tests were for FreeRTOS, which is no longer in the project

/*
TEST(TaskManGroup, TaskMan_ZeroTaskStackSizeTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t();
	CHECK(taskman->getErrorStatus() == taskman->INVALID_STACK_QUEUE_SIZE_ERR);
	delete taskman;
}

TEST(TaskManGroup, TaskMan_ZeroQueueSizeTest)
{

	TestTaskManager_t *taskman = new  TestTaskManager_t();
	CHECK(taskman->getErrorStatus() == taskman->INVALID_STACK_QUEUE_SIZE_ERR);
	delete taskman;
}

TEST(TaskManGroup, TaskMan_ZeroQueueAndStackSizeTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t();

	CHECK(taskman->getErrorStatus() == taskman->INVALID_STACK_QUEUE_SIZE_ERR);
	delete taskman;
}
*/

/*
TEST(TaskManGroup, TaskMan_SetTaskTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t();
	taskman->setTask("", nullptr);
	CHECK(taskman->getErrorStatus() == taskman->NULL_TASK_PTR_ERR);
	delete taskman;
}
*/
/*
TEST(TaskManGroup, TaskMan_SetQueueTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t();
	taskman->setQueue(nullptr);
	CHECK(taskman->getErrorStatus() == taskman->NULL_QUEUE_PTR_ERR);
	delete taskman;
}
*/

/*
TEST(TaskManGroup, TaskMan_QueueItemLowerBoundsTest)
{
	TestTaskManager_t *taskman = new  TestTaskManager_t();
	taskman->queueSendFromISR_wrapper(0);
	CHECK(taskman->getErrorStatus() == taskman->QUEUEITEM_OUTOFBOUNDS_ERR);
	delete taskman;
}
*/

