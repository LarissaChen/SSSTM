#ifndef DEBUG
#define DEBUG

#include "main.h"
#include "stm32f4xx_hal.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

HAL_StatusTypeDef Debug_Handle(void);
HAL_StatusTypeDef Debug_Init(void);

#endif

