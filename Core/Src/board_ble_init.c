/*
 * board_ble_init.c
 *
 *  Created on: Feb 29, 2024
 *      Author: Shankar
 */
#include "board_ble_init.h"
#include "main.h"

/* Private function prototypes -----------------------------------------------*/
void BLE_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */


/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void BLE_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();


  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(BT_SPI3_CS_GPIO_Port, BT_SPI3_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(BT_RST_GPIO_Port, BT_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : BT_EXT16_Pin ISM43362DRDY_EXT11_Pin */
  GPIO_InitStruct.Pin = BT_EXT16_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);


  /*Configure GPIO pin : BT_SPI3_CS_Pin */
  GPIO_InitStruct.Pin = BT_SPI3_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BT_SPI3_CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BT_RST_Pin */
  GPIO_InitStruct.Pin = BT_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BT_RST_GPIO_Port, &GPIO_InitStruct);



/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}


