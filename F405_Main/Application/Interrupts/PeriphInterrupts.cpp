/*
 * PeriphInterrupts.cpp
 *
 *  Created on: Apr 16, 2021
 *      Author: chris
 */



#include <PeriphInterrupts.hpp>

// HAL
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_tim.h"
#include "tim.h"
#include "stm32f4xx_hal_i2s.h"
#include "i2s.h"

#include <AppMain.hpp>

//#include <BaseTaskManager.hpp>
#include <I2STaskManager.hpp>

#include <DSPManager.hpp>
#include <Reverb.hpp>

#ifdef __cplusplus
	extern "C"
	{
#endif

	// defined in Core/Src/i2s.c
	extern DMA_HandleTypeDef hdma_i2s2_ext_rx;
	extern DMA_HandleTypeDef hdma_spi2_tx;

#ifdef USE_FREERTOS
	// defined in Application/AppMain.cpp
	extern ExtCtrlTaskManager_t *extctrl_taskman;
	extern I2STaskManager_t *i2s_taskman;
#else
	//extern ExtCtrlTaskManagerNoRTOS *extctrl_taskman_nortos;
	extern I2STskManNoRTOS *i2s_taskman_nortos;
#endif


	void setupPeriphInterrupts()
	{
		// Setup EXTI IRQ
		HAL_NVIC_SetPriority(EXTI0_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI0_IRQn);
		HAL_NVIC_SetPriority(EXTI1_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI1_IRQn);
		HAL_NVIC_SetPriority(EXTI2_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI2_IRQn);
		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
		HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

		// Setup DMA1_Stream3_IRQn for I2S receive
		HAL_NVIC_SetPriority(DMA1_Stream3_IRQn, 6, 0);
		HAL_NVIC_EnableIRQ(DMA1_Stream3_IRQn);

		// Setup DMA1_Stream4_IRQn for I2S transmit
		HAL_NVIC_SetPriority(DMA1_Stream4_IRQn, 6, 0);
		HAL_NVIC_EnableIRQ(DMA1_Stream4_IRQn);

		// enable the rotary encoders
		HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);
		HAL_TIM_Encoder_Start_IT(&htim4, TIM_CHANNEL_ALL);
	}


	void HAL_I2SEx_TxRxHalfCpltCallback(I2S_HandleTypeDef *hi2s){
#ifdef USE_FREERTOS
		i2s_taskman->queueSendFromISR_wrapper(1);
#else
		i2s_taskman_nortos->setCallbackStatus(i2s_taskman_nortos->Half);
#endif
		//HAL_GPIO_TogglePin(LEDA_G_GPIO_Port, LEDA_G_Pin);
	}

	void HAL_I2SEx_TxRxCpltCallback(I2S_HandleTypeDef *hi2s){
#ifdef USE_FREERTOS
		i2s_taskman->queueSendFromISR_wrapper(2);
#else
		i2s_taskman_nortos->setCallbackStatus(i2s_taskman_nortos->Full);
#endif

		//HAL_GPIO_TogglePin(LEDB_G_GPIO_Port, LEDB_G_Pin);

	}
	void EXTI0_IRQHandler(void)
	{

		// clear the EXTI pending bit
		EXTI->PR &= ~((EXTI_PR_PR0_Pos));
	}

	void EXTI1_IRQHandler(void)
	{

		// clear the EXTI pending bit
		EXTI->PR &= ~((EXTI_PR_PR1_Pos));
	}

	void EXTI2_IRQHandler(void)
	{

		// clear the EXTI pending bit
		EXTI->PR &= ~((EXTI_PR_PR2_Pos));
	}

	void EXTI15_10_IRQHandler(void)
	{
		#ifdef USE_FREERTOS
			// send EXTI message to task manager
			if((EXTI->PR & EXTI_PR_PR13_Msk) == EXTI_PR_PR13_Msk)
			{
				extctrl_taskman->queueSendFromISR_wrapper(EXTI_PR_PR13);
			}
			if((EXTI->PR & EXTI_PR_PR14_Msk) == EXTI_PR_PR14_Msk)
			{
				extctrl_taskman->queueSendFromISR_wrapper(EXTI_PR_PR14);
			}
		#else
			// send EXTI message to task manager
			if((EXTI->PR & EXTI_PR_PR13_Msk) == EXTI_PR_PR13_Msk)
			{
				//extctrl_taskman_nortos->nonRtosTask(EXTI_PR_PR13);
				if(i2s_taskman_nortos->getStateMachine() != nullptr)
					i2s_taskman_nortos->getStateMachine()->evFootswitchA();
			}
			if((EXTI->PR & EXTI_PR_PR14_Msk) == EXTI_PR_PR14_Msk)
			{
				//extctrl_taskman_nortos->nonRtosTask(EXTI_PR_PR14);
				if(i2s_taskman_nortos->getStateMachine() != nullptr)
					i2s_taskman_nortos->getStateMachine()->evFootswitchB();
			}
		#endif


		// clear the EXTI pending bit
		EXTI->PR &= ~((EXTI_PR_PR13_Pos));
		EXTI->PR &= ~((EXTI_PR_PR14_Pos));
	}


	//
	void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
	{
		BasicReverb* fx = (BasicReverb*)i2s_taskman_nortos->getDspManager()->getFx();
		fx->setWet(TIM3->CNT);
	}

	void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
	{
		if(htim->Instance == TIM11)
		{
			if(i2s_taskman_nortos->getDspManager()->getSampleMode() == DSPManager::MUTE_MODE)
			{
				DSPManager::unmute();
				TIM11->SR = 0;
				// toggle relay to enable FX signal path
				HAL_GPIO_TogglePin(RelayCoil_OUT_GPIO_Port, RelayCoil_OUT_Pin);
			}
		}
	}


	void DMA1_Stream3_IRQHandler(void)
	{

		HAL_DMA_IRQHandler(&hdma_i2s2_ext_rx);

	}

	void DMA1_Stream4_IRQHandler(void)
	{

	  HAL_DMA_IRQHandler(&hdma_spi2_tx);

	}

/*	void TIM1_TRG_COM_TIM11_IRQHandler(void)
	{

	  HAL_TIM_IRQHandler(&htim11);

	}
	*/

#ifdef __cplusplus
	}
#endif
