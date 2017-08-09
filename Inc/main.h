/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define DIR_LUN1_Pin GPIO_PIN_3
#define DIR_LUN1_GPIO_Port GPIOE
#define EN_LUN1_Pin GPIO_PIN_4
#define EN_LUN1_GPIO_Port GPIOE
#define PUL_LUN1_Pin GPIO_PIN_5
#define PUL_LUN1_GPIO_Port GPIOE
#define PUL_STEP1_Pin GPIO_PIN_6
#define PUL_STEP1_GPIO_Port GPIOE
#define DIR_STEP1_Pin GPIO_PIN_13
#define DIR_STEP1_GPIO_Port GPIOC
#define EN_STEP1_Pin GPIO_PIN_14
#define EN_STEP1_GPIO_Port GPIOC
#define ENC1Z_Pin GPIO_PIN_15
#define ENC1Z_GPIO_Port GPIOC
#define ENC1Z_EXTI_IRQn EXTI15_10_IRQn
#define RCC_OSC_OUT_Pin GPIO_PIN_1
#define RCC_OSC_OUT_GPIO_Port GPIOH
#define ENC1A_Pin GPIO_PIN_0
#define ENC1A_GPIO_Port GPIOA
#define ENC1B_Pin GPIO_PIN_1
#define ENC1B_GPIO_Port GPIOA
#define TX1_Pin GPIO_PIN_2
#define TX1_GPIO_Port GPIOA
#define RX1_Pin GPIO_PIN_3
#define RX1_GPIO_Port GPIOA
#define DIR_LUN2_Pin GPIO_PIN_4
#define DIR_LUN2_GPIO_Port GPIOA
#define EN_LUN2_Pin GPIO_PIN_5
#define EN_LUN2_GPIO_Port GPIOA
#define PUL_LUN2_Pin GPIO_PIN_6
#define PUL_LUN2_GPIO_Port GPIOA
#define PUL_STEP2_Pin GPIO_PIN_7
#define PUL_STEP2_GPIO_Port GPIOA
#define DIR_STEP2_Pin GPIO_PIN_4
#define DIR_STEP2_GPIO_Port GPIOC
#define EN_STEP2_Pin GPIO_PIN_5
#define EN_STEP2_GPIO_Port GPIOC
#define ENC2A_Pin GPIO_PIN_9
#define ENC2A_GPIO_Port GPIOE
#define ENC2B_Pin GPIO_PIN_11
#define ENC2B_GPIO_Port GPIOE
#define ENC2Z_Pin GPIO_PIN_12
#define ENC2Z_GPIO_Port GPIOE
#define ENC2Z_EXTI_IRQn EXTI15_10_IRQn
#define GREEN_Pin GPIO_PIN_14
#define GREEN_GPIO_Port GPIOE
#define RED_Pin GPIO_PIN_15
#define RED_GPIO_Port GPIOE
#define TX2_Pin GPIO_PIN_10
#define TX2_GPIO_Port GPIOB
#define RX2_Pin GPIO_PIN_11
#define RX2_GPIO_Port GPIOB
#define DIR_LUN4_Pin GPIO_PIN_12
#define DIR_LUN4_GPIO_Port GPIOB
#define EN_LUN4_Pin GPIO_PIN_13
#define EN_LUN4_GPIO_Port GPIOB
#define PUL_LUN4_Pin GPIO_PIN_14
#define PUL_LUN4_GPIO_Port GPIOB
#define PUL_STEP4_Pin GPIO_PIN_15
#define PUL_STEP4_GPIO_Port GPIOB
#define DIR_STEP4_Pin GPIO_PIN_8
#define DIR_STEP4_GPIO_Port GPIOD
#define EN_STEP4_Pin GPIO_PIN_9
#define EN_STEP4_GPIO_Port GPIOD
#define ENC4Z_Pin GPIO_PIN_11
#define ENC4Z_GPIO_Port GPIOD
#define ENC4Z_EXTI_IRQn EXTI15_10_IRQn
#define ENC4A_Pin GPIO_PIN_12
#define ENC4A_GPIO_Port GPIOD
#define ENC4B_Pin GPIO_PIN_13
#define ENC4B_GPIO_Port GPIOD
#define TX3_Pin GPIO_PIN_6
#define TX3_GPIO_Port GPIOC
#define RX3_Pin GPIO_PIN_7
#define RX3_GPIO_Port GPIOC
#define SYS_JTMS_SWDIO_Pin GPIO_PIN_13
#define SYS_JTMS_SWDIO_GPIO_Port GPIOA
#define SYS_JTCK_SWCLK_Pin GPIO_PIN_14
#define SYS_JTCK_SWCLK_GPIO_Port GPIOA
#define TX4_Pin GPIO_PIN_10
#define TX4_GPIO_Port GPIOC
#define RX4_Pin GPIO_PIN_11
#define RX4_GPIO_Port GPIOC
#define Debug_TX_Pin GPIO_PIN_12
#define Debug_TX_GPIO_Port GPIOC
#define Debug_RX_Pin GPIO_PIN_2
#define Debug_RX_GPIO_Port GPIOD
#define ENC3Z_Pin GPIO_PIN_3
#define ENC3Z_GPIO_Port GPIOB
#define ENC3Z_EXTI_IRQn EXTI3_IRQn
#define ENC3A_Pin GPIO_PIN_4
#define ENC3A_GPIO_Port GPIOB
#define ENC3B_Pin GPIO_PIN_5
#define ENC3B_GPIO_Port GPIOB
#define DIR_LUN3_Pin GPIO_PIN_6
#define DIR_LUN3_GPIO_Port GPIOB
#define EN_LUN3_Pin GPIO_PIN_7
#define EN_LUN3_GPIO_Port GPIOB
#define PUL_LUN3_Pin GPIO_PIN_8
#define PUL_LUN3_GPIO_Port GPIOB
#define PUL_STEP3_Pin GPIO_PIN_9
#define PUL_STEP3_GPIO_Port GPIOB
#define DIR_STEP3_Pin GPIO_PIN_0
#define DIR_STEP3_GPIO_Port GPIOE
#define EN_STEP3_Pin GPIO_PIN_1
#define EN_STEP3_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
