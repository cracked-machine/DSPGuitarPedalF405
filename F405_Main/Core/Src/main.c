/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2s.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>
#include "AppMain.hpp"
#include "arm_math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

	#define BLOCK_SIZE_FLOAT 512
	//#define STEREO_SINGLE_BLK_SIZE_U16 2048

	arm_biquad_casd_df1_inst_f32 left_iir_settings, right_iir_settings;

	//4 delayed samples per biquad
	float iir_left_state [4];
	float iir_right_state [4];


	//IIR low-pass, fs=48kHz, f_cut=1kHz, q=0.707
	float iir_coeffs [5] = {
					0.003916123487156427f,
					0.007832246974312854f,
					0.003916123487156427f,
					1.8153396116625289f,
					-0.8310041056111546
	};




//	uint16_t rxBufBlock[STEREO_SINGLE_BLK_SIZE_U16*2];
//	uint16_t txBufBlock[STEREO_SINGLE_BLK_SIZE_U16*2];
	float left_buf_in [BLOCK_SIZE_FLOAT*2];
	float right_buf_in [BLOCK_SIZE_FLOAT*2];
	float left_buf_out [BLOCK_SIZE_FLOAT*2];
	float right_buf_out [BLOCK_SIZE_FLOAT*2];

	//uint8_t callback_state = 0;

	int offset_read_ptr;
	int offset_write_ptr, write_ptr;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/*
void HAL_I2SEx_TxRxHalfCpltCallback(I2S_HandleTypeDef *hi2s){

	callback_state = 1;

}

void HAL_I2SEx_TxRxCpltCallback(I2S_HandleTypeDef *hi2s){

	callback_state = 2;

}

void do_iir_init()
{
  arm_biquad_cascade_df1_init_f32 ( &left_iir_settings, 1, &iir_coeffs[0], &iir_left_state[0]);
  arm_biquad_cascade_df1_init_f32 ( &right_iir_settings, 1, &iir_coeffs[0], &iir_right_state[0]);


  //int res = testfunc();
  HAL_I2SEx_TransmitReceive_DMA (&hi2s2, txBufBlock, rxBufBlock, STEREO_SINGLE_BLK_SIZE_U16);


}

void do_iir_loop()
{
  if (callback_state != 0) {

	  //decide if it was half or cplt callback
	  if (callback_state == 1)   {
			  offset_read_ptr = 0;
			  offset_write_ptr = 0;
			  write_ptr = 0;
	  }

	  else if (callback_state == 2) {
		  offset_read_ptr = STEREO_SINGLE_BLK_SIZE_U16;
		  offset_write_ptr = BLOCK_SIZE_FLOAT;
		  write_ptr = BLOCK_SIZE_FLOAT;
	  }


	  //restore input sample buffer to float array
	  for (int i=offset_read_ptr; i<offset_read_ptr+STEREO_SINGLE_BLK_SIZE_U16; i=i+4) {
		  left_buf_in[write_ptr] = (float) ((int) (rxBufBlock[i]<<16)|rxBufBlock[i+1]);
		  right_buf_in[write_ptr] = (float) ((int) (rxBufBlock[i+2]<<16)|rxBufBlock[i+3]);
		  write_ptr++;
	  }


	  //process IIR
	  arm_biquad_cascade_df1_f32 (&left_iir_settings, &left_buf_in[offset_write_ptr], &left_buf_out[offset_write_ptr],BLOCK_SIZE_FLOAT);
	  arm_biquad_cascade_df1_f32 (&right_iir_settings, &right_buf_in[offset_write_ptr], &right_buf_out[offset_write_ptr],BLOCK_SIZE_FLOAT);


	  //restore processed float-array to output sample-buffer
	  write_ptr = offset_write_ptr;

	  for (int i=offset_read_ptr; i<offset_read_ptr+STEREO_SINGLE_BLK_SIZE_U16; i=i+4) {
			txBufBlock[i] =  (((int)left_buf_out[write_ptr])>>16)&0xFFFF;
			txBufBlock[i+1] = ((int)left_buf_out[write_ptr])&0xFFFF;
			txBufBlock[i+2] = (((int)left_buf_out[write_ptr])>>16)&0xFFFF;
			txBufBlock[i+3] = ((int)left_buf_out[write_ptr])&0xFFFF;
			write_ptr++;
	  }

	  callback_state = 0;

  }
}




void HAL_I2S_ErrorCallback(I2S_HandleTypeDef *hi2s)
{
	callback_state = 0;
}
*/
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2S2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM14_Init();
  MX_TIM11_Init();
  /* USER CODE BEGIN 2 */

  appmain();
  //HAL_GPIO_TogglePin(RelayCoil_OUT_GPIO_Port, RelayCoil_OUT_Pin);


  //do_iir_init();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //do_iir_loop();

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 15;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2S;
  PeriphClkInitStruct.PLLI2S.PLLI2SN = 160;
  PeriphClkInitStruct.PLLI2S.PLLI2SR = 2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {

  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
