/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    app_threadx.c
  * @author  MCD Application Team
  * @brief   ThreadX applicative file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020-2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "app_threadx.h"
#include "azure_config.h"
#include "stm_networking.h"
#include "sntp_client.h"
#include   "nxd_http_server.h"
#include "board_wifi_init.h"
#include "board_ble_init.h"
#include "app_bluenrg_ms.h"
#include "wifi.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
TX_THREAD tx_app_thread;
TX_SEMAPHORE tx_app_semaphore;
TX_THREAD tx_ble_thread;

//TX_THREAD       server_thread;
/* USER CODE BEGIN PV */
//NX_IP nx_ip;
//NX_PACKET_POOL nx_pool;
//NX_DNS nx_dns_client;
//NXD_ADDRESS     server_ip_address;
//NX_HTTP_SERVER  my_server;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
extern void thread_server_entry(ULONG);
/* USER CODE END PFP */


/**
  * @brief  Application ThreadX Initialization.
  * @param memory_ptr: memory pointer
  * @retval int
  */
UINT App_ThreadX_Init(VOID *memory_ptr)
{
  UINT ret = TX_SUCCESS;
  NX_PACKET_POOL *byte_pool = (NX_PACKET_POOL*)memory_ptr;
  /* USER CODE BEGIN App_ThreadX_MEM_POOL */

  /* USER CODE END App_ThreadX_MEM_POOL */
  CHAR *pointer;

  /* Allocate the stack for tx app thread  */
  if (tx_byte_allocate(byte_pool, (VOID**) &pointer,
                       TX_APP_STACK_SIZE, TX_NO_WAIT) != TX_SUCCESS)
  {
    return TX_POOL_ERROR;
  }
  /* Create tx app thread.  */
  if (tx_thread_create(&tx_ble_thread, "tx ble thread", tx_ble_thread_entry, 0, pointer,
                       TX_APP_STACK_SIZE, 12, TX_APP_THREAD_PREEMPTION_THRESHOLD,
                       TX_APP_THREAD_TIME_SLICE, TX_APP_THREAD_AUTO_START) != TX_SUCCESS)
  {
    return TX_THREAD_ERROR;
  }
  if (tx_byte_allocate(byte_pool, (VOID**) &pointer,
                       TX_APP_STACK_SIZE, TX_NO_WAIT) != TX_SUCCESS)
  {
    return TX_POOL_ERROR;
  }
  /* Create tx app thread.  */
  if (tx_thread_create(&tx_app_thread, "tx app thread", tx_app_thread_entry, 0, pointer,
                       TX_APP_STACK_SIZE, 11, TX_APP_THREAD_PREEMPTION_THRESHOLD,
                       TX_APP_THREAD_TIME_SLICE, TX_APP_THREAD_AUTO_START) != TX_SUCCESS)
  {
    return TX_THREAD_ERROR;
  }

  /* Create tx app semaphore.  */
  if (tx_semaphore_create(&tx_app_semaphore, "tx app semaphore", 0) != TX_SUCCESS)
  {
    return TX_SEMAPHORE_ERROR;
  }
#if 0
  if (tx_byte_allocate(byte_pool, (VOID**) &pointer,
                       TX_APP_STACK_SIZE, TX_NO_WAIT) != TX_SUCCESS)
  {
    return TX_POOL_ERROR;
  }
  if(tx_thread_create(&server_thread, "HTTP Server thread", thread_server_entry, 0,
		  pointer, TX_APP_STACK_SIZE,TX_APP_THREAD_PRIO, TX_APP_THREAD_PREEMPTION_THRESHOLD, TX_NO_TIME_SLICE, TX_DONT_START)!=TX_SUCCESS)
  {
    return TX_THREAD_ERROR;
  }
#endif
  /* USER CODE BEGIN App_ThreadX_Init */


  /* USER CODE END App_ThreadX_Init */

  return ret;
}
/**
  * @brief  Function implementing the tx_app_thread_entry thread.
  * @param  thread_input: Hardcoded to 0.
  * @retval None
  */
void tx_ble_thread_entry(ULONG thread_input)
{
  /* USER CODE BEGIN tx_app_thread_entry */
    //UINT status;

    printf("Starting Azure thread\r\n\r\n");
    BLE_GPIO_Init();
    if(memory_driver_read()==1)
    {
    	//ble_gpio_init();
    	MX_BlueNRG_MS_Init();
		while(1){
			MX_BlueNRG_MS_Process();
			if(WiFi_PWD_Memory[0]!='\n')
			{
				break;
			}
		}
		tx_thread_sleep(100);
		copy_data();
		memory_driver_write();
    }
	HCI_TL_SPI_DeInit();
	HCI_TL_SPI_Reset();
    tx_semaphore_put(&tx_app_semaphore);

	while(1)
	{
		//tx_thread_resume(&tx_app_thread);
		tx_thread_sleep(100);
	}
	//tx_thread_resume(&tx_app_thread);

    // Initialize the network

  /* USER CODE END tx_app_thread_entry */
}
/**
  * @brief  Function implementing the tx_app_thread_entry thread.
  * @param  thread_input: Hardcoded to 0.
  * @retval None
  */
void tx_app_thread_entry(ULONG thread_input)
{
  /* USER CODE BEGIN tx_app_thread_entry */
    UINT status;

    printf("Starting Azure thread\r\n\r\n");
	//tx_thread_suspend(&tx_ble_thread);
    tx_semaphore_get(&tx_app_semaphore, TX_WAIT_FOREVER);
    WIFI_IO_INIT();


    // Initialize the network
    if (status = stm_network_init(WIFI_SSID, WIFI_PASSWORD, WIFI_MODE))
    {
        printf("ERROR: Failed to initialize the network (0x%08x)\r\n", status);
        if(status==255)
        {
        	//restart system
        }
    }

    //else if ((status = http_server_entry(&nx_ip, &nx_pool, &nx_dns_client, sntp_time)))
    //{
        //printf("ERROR: Failed to run Azure IoT (0x%04x)\r\n", status);
    //}

  /* USER CODE END tx_app_thread_entry */
}

  /**
  * @brief  Function that implements the kernel's initialization.
  * @param  None
  * @retval None
  */
void MX_ThreadX_Init(void)
{
  /* USER CODE BEGIN  Before_Kernel_Start */

  /* USER CODE END  Before_Kernel_Start */

  tx_kernel_enter();

  /* USER CODE BEGIN  Kernel_Start_Error */

  /* USER CODE END  Kernel_Start_Error */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
