/*
 * i2STaskManager.cpp
 *
 *  Created on: Apr 15, 2021
 *      Author: chris
 */



#include <I2STaskManager.hpp>
#include <iostream>
#include "gpio.h"
#include "stm32f4xx_hal.h"



void I2STaskCode( void * parm );

static StaticQueue_t I2SStaticQueue;

I2STaskManager::I2STaskManager()
{
	I2STaskHandle = NULL;

}

void I2STaskManager::initTask()
{
	// Create the task without using any dynamic memory allocation.
	I2STaskHandle = xTaskCreateStatic(
		I2STaskCode,       		// global function in ExtCtrlTaskManager
		"I2STaskMan",          	// Text name for the task.
		200,      				// Number of indexes in the ISRTaskStack array.
		this,    				// pointer to this class instance (used by "IRSTaskMan" to access class members)
		tskIDLE_PRIORITY,		// Priority at which the task is created.
		I2STaskStack,           // Array to use as the task's stack.
		&I2STaskBuffer );  		// Variable to hold the task's data structure.
}

void I2STaskManager::initQueue()
{
	/* Create a queue capable of containing 10 uint64_t values. */
	I2SQueue = ISRQueueCreateStatic(
		1,						// QUEUE_SIZE
		sizeof(uint16_t),		// ITEM_SIZE
		I2SQueueStorageArea,	// total queue storage size (QUEUE_SIZE * ITEM_SIZE)
		&I2SStaticQueue );		// Queue data structure
}

TaskHandle_t I2STaskManager::getTask()
{
	return this->I2STaskHandle;
}

QueueHandle_t I2STaskManager::getQueue()
{
	return this->I2SQueue;
}

void I2STaskManager::queueSendFromISR_wrapper(uint8_t item)
{
	//ISRQueueSendFromISR(I2SQueue, &item, NULL);
	ISRQueueOverwriteFromISR(I2SQueue, &item, NULL);
}

/* Function that implements the task being created. */
void I2STaskCode( void * parm )
{
	I2STaskManager *i2s_taskman = static_cast<I2STaskManager*>(parm);



	while(1)
	{
		uint8_t item = 0;
		//std::cout << "I2STaskCode retrieved queue item" << item << std::endl;
		if( ISRQueueReceive( i2s_taskman->getQueue(), &( item ), ( TickType_t ) 0 ) == pdPASS)
		{
			if(item == 1)
				HAL_GPIO_TogglePin(LEDA_R_GPIO_Port, LEDA_G_Pin);
			if(item == 2)
				HAL_GPIO_TogglePin(LEDB_R_GPIO_Port, LEDB_G_Pin);

		}
	}
}
