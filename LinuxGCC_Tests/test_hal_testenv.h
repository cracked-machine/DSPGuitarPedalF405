/*
 * test_debounce.h
 *
 *  Created on: 17 Apr 2021
 *      Author: chris
 */

#ifndef TEST_HAL_TESTENV_H_
#define TEST_HAL_TESTENV_H_


#include <stdint.h>
#include <cstdlib>


typedef struct
{
  volatile uint32_t CR1;         //!< TIM control register 1,              Address offset: 0x00
  volatile uint32_t CR2;         //!< TIM control register 2,              Address offset: 0x04
  volatile uint32_t SMCR;        //!< TIM slave mode control register,     Address offset: 0x08
  volatile uint32_t DIER;        //!< TIM DMA/interrupt enable register,   Address offset: 0x0C
  volatile uint32_t SR;          //!< TIM status register,                 Address offset: 0x10
  volatile uint32_t EGR;         //!< TIM event generation register,       Address offset: 0x14
  volatile uint32_t CCMR1;       //!< TIM capture/compare mode register 1, Address offset: 0x18
  volatile uint32_t CCMR2;       //!< TIM capture/compare mode register 2, Address offset: 0x1C
  volatile uint32_t CCER;        //!< TIM capture/compare enable register, Address offset: 0x20
  volatile uint32_t CNT;         //!< TIM counter register,                Address offset: 0x24
  volatile uint32_t PSC;         //!< TIM prescaler,                       Address offset: 0x28
  volatile uint32_t ARR;         //!< TIM auto-reload register,            Address offset: 0x2C
  volatile uint32_t RCR;         //!< TIM repetition counter register,     Address offset: 0x30
  volatile uint32_t CCR1;        //!< TIM capture/compare register 1,      Address offset: 0x34
  volatile uint32_t CCR2;        //!< TIM capture/compare register 2,      Address offset: 0x38
  volatile uint32_t CCR3;        //!< TIM capture/compare register 3,      Address offset: 0x3C
  volatile uint32_t CCR4;        //!< TIM capture/compare register 4,      Address offset: 0x40
  volatile uint32_t BDTR;        //!< TIM break and dead-time register,    Address offset: 0x44
  volatile uint32_t DCR;         //!< TIM DMA control register,            Address offset: 0x48
  volatile uint32_t DMAR;        //!< TIM DMA address for full transfer,   Address offset: 0x4C
  volatile uint32_t OR;          //!< TIM option register,                 Address offset: 0x50
} TIM_TypeDef;



#define TIM_CR1_CEN_Pos           (0U)
#define TIM_CR1_CEN_Msk           (0x1UL << TIM_CR1_CEN_Pos)                   //!< 0x00000001

#define EXTI_PR_PR13_Pos          (13U)
#define EXTI_PR_PR13_Msk          (0x1UL << EXTI_PR_PR13_Pos)                   /*!< 0x00002000 */
#define EXTI_PR_PR13              EXTI_PR_PR13_Msk                             /*!< Pending bit for line 13 */
#define EXTI_PR_PR14_Pos          (14U)
#define EXTI_PR_PR14_Msk          (0x1UL << EXTI_PR_PR14_Pos)                   /*!< 0x00004000 */
#define EXTI_PR_PR14              EXTI_PR_PR14_Msk                             /*!< Pending bit for line 14 */


#endif /* TEST_HAL_TESTENV_H_ */
