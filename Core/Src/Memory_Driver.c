/*
 * Memory_Driver.c
 *
 *  Created on: Mar 3, 2024
 *      Author: Shankar
 */
/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#include "main.h"
#include "string.h"
#define FLASH_ROW_SIZE          64

/* !!! Be careful the user area should be in another bank than the code !!! */
#define FLASH_USER_START_ADDR   ADDR_FLASH_PAGE_254   /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     ADDR_FLASH_PAGE_255 + FLASH_PAGE_SIZE - 1   /* End @ of user Flash area */
/* USER CODE END PTD */

/* Private variables ---------------------------------------------------------*/
uint32_t BankNumber = 0;
uint32_t Address = 0, PAGEError = 0;
__IO uint32_t MemoryProgramStatus = 0;
__IO uint64_t data64 = 0;

/*Variable used for Erase procedure*/
static FLASH_EraseInitTypeDef EraseInitStruct;
union UT_FALSH_DATA
{
	__IO uint64_t dummy[255];
	struct T_FLASH_DATA
	{
		uint16_t MagicNumber;                                      /**< A magic number to mark the data in flash as valid (0xABCD) */

		uint8_t  wifi_ssid_memory[20];                                          /**< The currently selected protocol */
		uint8_t  wifi_pwd_memory[50];                                          /**< The currently selected protocol */
	}ConfigData;
}U_ConfigData;
static uint32_t GetBank(uint32_t Address);


/**
  * @brief  Gets the bank of a given address
  * @param  Addr: Address of the FLASH Memory
  * @retval The bank of a given address
  */
static uint32_t GetBank(uint32_t Addr)
{
  uint32_t bank = 0;

  if (READ_BIT(SYSCFG->MEMRMP, SYSCFG_MEMRMP_FB_MODE) == 0)
  {
  	/* No Bank swap */
    if (Addr < (FLASH_BASE + FLASH_BANK_SIZE))
    {
      bank = FLASH_BANK_1;
    }
    else
    {
      bank = FLASH_BANK_2;
    }
  }
  else
  {
  	/* Bank swap */
    if (Addr < (FLASH_BASE + FLASH_BANK_SIZE))
    {
      bank = FLASH_BANK_2;
    }
    else
    {
      bank = FLASH_BANK_1;
    }
  }

  return bank;
}

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */

int memory_driver_write(void)
{
	  /* Erase the user Flash area
	    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/
	  /* Unlock the Flash to enable the flash control register access *************/
	  HAL_FLASH_Unlock();

	  /* Clear OPTVERR bit set on virgin samples */
	  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);

	  /* Get the bank */
	  BankNumber = GetBank(FLASH_USER_START_ADDR);

	  /* Fill EraseInit structure*/
	  EraseInitStruct.TypeErase = FLASH_TYPEERASE_MASSERASE;
	  EraseInitStruct.Banks     = BankNumber;

	  if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK)
	  {
	    /*
	      Error occurred while mass erase.
	      User can add here some code to deal with this error.
	      To know the code error, user can call function 'HAL_FLASH_GetError()'
	    */
	    /* Infinite loop */
		  return 0;
	  }
	  /* Unlock the Flash to enable the flash control register access *************/
	  /* Program the user Flash area word by word
	    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/

	  Address = FLASH_USER_START_ADDR;

	  while (Address < (FLASH_USER_END_ADDR - (FLASH_ROW_SIZE*sizeof(uint64_t))))
	  {
	    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_FAST, Address, &U_ConfigData.dummy) == HAL_OK)
	    {
	      Address = Address + (FLASH_ROW_SIZE*sizeof(uint64_t));
	    }
	   else
	    {
	      /* Error occurred while writing data in Flash memory.
	         User can add here some code to deal with this error */
		  HAL_FLASH_Lock();
		  return 0;
	    }
	  }

	  if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_FAST_AND_LAST, Address, &U_ConfigData.dummy) != HAL_OK)
	  {
	    /* Error occurred while writing data in Flash memory.
	       User can add here some code to deal with this error */
		  HAL_FLASH_Lock();
		  return 0;
	  }

	  /* Lock the Flash to disable the flash control register access (recommended
	     to protect the FLASH memory against possible unwanted operation) *********/
	  HAL_FLASH_Lock();
	  return 1;

}

int memory_driver_read(void)
{
	uint8_t data_index = 0;
	  /* Unlock the Flash to enable the flash control register access *************/
	  /* Program the user Flash area word by word
	    (area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/
	  /* Check if the programmed data is OK
	      MemoryProgramStatus = 0: data programmed correctly
	      MemoryProgramStatus != 0: number of words not programmed correctly ******/
	  Address = FLASH_USER_START_ADDR;
	  MemoryProgramStatus = 0x0;

	  while (Address < FLASH_USER_END_ADDR)
	  {
	    for (data_index = 0; data_index < FLASH_ROW_SIZE; data_index++)
	    {
	    	U_ConfigData.dummy[data_index] = *(__IO uint64_t *)Address;

	      //if(data64 != Data64_To_Prog[data_index])
	      //{
	        //MemoryProgramStatus++;
	      //}
	      Address = Address + sizeof(uint64_t);
	    }
	  }

	  /*Check if there is an issue to program data*/
	  if((strlen(U_ConfigData.ConfigData.wifi_ssid_memory)<1)||(strlen(U_ConfigData.ConfigData.wifi_pwd_memory)<1))
	  {
		  MemoryProgramStatus=1;
	  }

	  if (MemoryProgramStatus == 0)
	  {
	    /* No error detected. Switch on LED1*/
		  memcpy(&WiFi_SSID_Memory,U_ConfigData.ConfigData.wifi_ssid_memory,sizeof(char)*20);
		  memcpy(&WiFi_PWD_Memory,U_ConfigData.ConfigData.wifi_pwd_memory,sizeof(char)*20);
	  	  return 0;
	  }
	  else
	  {
	    /* Error detected. Switch on LED2*/
		  return 1;
	  }


}

void copy_data(void)
{
	  U_ConfigData.ConfigData.MagicNumber = 0xABCD;
	  memcpy(&U_ConfigData.ConfigData.wifi_ssid_memory,&WiFi_SSID_Memory,sizeof(char)*20);
	  memcpy(&U_ConfigData.ConfigData.wifi_pwd_memory,&WiFi_PWD_Memory,sizeof(char)*20);

}
