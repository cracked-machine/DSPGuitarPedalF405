/*
 * SystemInterrupts.c
 *
 *  Created on: Apr 16, 2021
 *      Author: chris
 */

#include "stm32f4xx_hal.h"


#ifdef __cplusplus
	extern "C"
	{
#endif

	/**
	  * @brief This function handles Non maskable interrupt.
	  */
	void NMI_Handler(void)
	{
	  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

	  /* USER CODE END NonMaskableInt_IRQn 0 */
	  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
	  while (1)
	  {
	  }
	  /* USER CODE END NonMaskableInt_IRQn 1 */
	}

	/**
	  * @brief This function handles Hard fault interrupt.
	  */
	void HardFault_Handler(void)
	{
	  /* USER CODE BEGIN HardFault_IRQn 0 */

	  /* USER CODE END HardFault_IRQn 0 */
	  while (1)
	  {
	    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
	    /* USER CODE END W1_HardFault_IRQn 0 */
	  }
	}

	/**
	  * @brief This function handles Memory management fault.
	  */
	void MemManage_Handler(void)
	{
	  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

	  /* USER CODE END MemoryManagement_IRQn 0 */
	  while (1)
	  {
	    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
	    /* USER CODE END W1_MemoryManagement_IRQn 0 */
	  }
	}

	/**
	  * @brief This function handles Pre-fetch fault, memory access fault.
	  */
	void BusFault_Handler(void)
	{
	  /* USER CODE BEGIN BusFault_IRQn 0 */

	  /* USER CODE END BusFault_IRQn 0 */
	  while (1)
	  {
	    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
	    /* USER CODE END W1_BusFault_IRQn 0 */
	  }
	}

	/**
	  * @brief This function handles Undefined instruction or illegal state.
	  */
	void UsageFault_Handler(void)
	{
	  /* USER CODE BEGIN UsageFault_IRQn 0 */

	  /* USER CODE END UsageFault_IRQn 0 */
	  while (1)
	  {
	    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
	    /* USER CODE END W1_UsageFault_IRQn 0 */
	  }
	}

	/**
	  * @brief This function handles Debug monitor.
	  */
	void DebugMon_Handler(void)
	{
	  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

	  /* USER CODE END DebugMonitor_IRQn 0 */
	  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

	  /* USER CODE END DebugMonitor_IRQn 1 */
	}

	/**
	  * @brief This function handles System service call via SWI instruction.
	  */
	__attribute__((weak)) void SVC_Handler(void)
	{
	  /* USER CODE BEGIN SVCall_IRQn 0 */

	  /* USER CODE END SVCall_IRQn 0 */
	  /* USER CODE BEGIN SVCall_IRQn 1 */

	  /* USER CODE END SVCall_IRQn 1 */
	}

	/**
	  * @brief This function handles Pendable request for system service.
	  */
	__attribute__((weak)) void PendSV_Handler(void)
	{
	  /* USER CODE BEGIN PendSV_IRQn 0 */

	  /* USER CODE END PendSV_IRQn 0 */
	  /* USER CODE BEGIN PendSV_IRQn 1 */

	  /* USER CODE END PendSV_IRQn 1 */
	}

	/**
	  * @brief This function handles System tick timer.
	  */
	/*__attribute__((weak))*/ void SysTick_Handler(void)
	{
		// if using HW Timesource comment this line and uncomment the "weak" attribute in this function signature
		HAL_IncTick();
	}



#ifdef __cplusplus
	}
#endif

