#ifndef LUN
#define LUN
#include "main.h"
#include "stm32f4xx_hal.h"
#include "can.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"



HAL_StatusTypeDef Motor_Start(uint8_t motornum);
HAL_StatusTypeDef Motor_Stop(uint8_t motornum);
HAL_StatusTypeDef Motor_Speed_Enable(uint8_t motornum);
HAL_StatusTypeDef Motor_Speed_Add(uint8_t motornum,double speed);
void Motor_Init(uint8_t motornum);
HAL_StatusTypeDef Motor_Speed_Set(uint8_t motornum,uint16_t speed);
HAL_StatusTypeDef Motor_Clear_Error(uint8_t motornum);
#endif
