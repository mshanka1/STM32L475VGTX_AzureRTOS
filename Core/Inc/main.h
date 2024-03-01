/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32l4xx_hal.h"
#include "hci_tl_interface.h"
#include "b_l475e_iot01a2.h"

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
#define BT_EXT16_Pin GPIO_PIN_6
#define BT_EXT16_GPIO_Port GPIOE
#define BT_EXT16_EXTI_IRQn EXTI9_5_IRQn
#define BSP_BUTTON_EXTI_IRQn EXTI15_10_IRQn
#define ISM43362_RST_Pin GPIO_PIN_8
#define ISM43362_RST_GPIO_Port GPIOE
#define BT_SPI3_CS_Pin GPIO_PIN_13
#define BT_SPI3_CS_GPIO_Port GPIOD
#define BT_RST_Pin GPIO_PIN_8
#define BT_RST_GPIO_Port GPIOA
#define ISM43662_SPI_SCK_Pin GPIO_PIN_10
#define ISM43662_SPI_SCK_GPIO_Port GPIOC
#define ISM43662_SPI_MISO_Pin GPIO_PIN_11
#define ISM43662_SPI_MISO_GPIO_Port GPIOC
#define ISM43662_SPI_MOSI_Pin GPIO_PIN_12
#define ISM43662_SPI_MOSI_GPIO_Port GPIOC
#define ISM43362_SPI3_CSN_Pin GPIO_PIN_0
#define ISM43362_SPI3_CSN_GPIO_Port GPIOE
#define ISM43362DRDY_EXT11_Pin GPIO_PIN_1
#define ISM43362DRDY_EXT11_GPIO_Port GPIOE
#define ISM43362DRDY_EXT11_EXTI_IRQn EXTI1_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
