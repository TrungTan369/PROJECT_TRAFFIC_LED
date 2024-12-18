/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define A_Pin GPIO_PIN_0
#define A_GPIO_Port GPIOF
#define EN1_Pin GPIO_PIN_1
#define EN1_GPIO_Port GPIOF
#define EN0_Pin GPIO_PIN_0
#define EN0_GPIO_Port GPIOA
#define BUTTON3_Pin GPIO_PIN_1
#define BUTTON3_GPIO_Port GPIOA
#define R1_Pin GPIO_PIN_2
#define R1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_3
#define BUTTON2_GPIO_Port GPIOA
#define Y0_Pin GPIO_PIN_4
#define Y0_GPIO_Port GPIOA
#define C_Pin GPIO_PIN_5
#define C_GPIO_Port GPIOA
#define B_Pin GPIO_PIN_6
#define B_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_7
#define BUTTON1_GPIO_Port GPIOA
#define LED_DEBUG_Pin GPIO_PIN_0
#define LED_DEBUG_GPIO_Port GPIOB
#define D_Pin GPIO_PIN_1
#define D_GPIO_Port GPIOB
#define G0_Pin GPIO_PIN_8
#define G0_GPIO_Port GPIOA
#define SCL_Pin GPIO_PIN_9
#define SCL_GPIO_Port GPIOA
#define SDA_Pin GPIO_PIN_10
#define SDA_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_11
#define EN3_GPIO_Port GPIOA
#define R0_Pin GPIO_PIN_12
#define R0_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_3
#define EN2_GPIO_Port GPIOB
#define G1_Pin GPIO_PIN_4
#define G1_GPIO_Port GPIOB
#define Y1_Pin GPIO_PIN_5
#define Y1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
