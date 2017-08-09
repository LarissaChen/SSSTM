#ifndef WMDSTEP
#define WMDSTEP


#include <main.h>
#include "stm32f4xx_hal.h"
#include "can.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

HAL_StatusTypeDef Step_Init(void);
HAL_StatusTypeDef Step_Set(uint8_t motornum,int32_t step);
#endif
