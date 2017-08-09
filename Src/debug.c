#include "debug.h"
#include "stm32f4xx_hal_uart.h"
void Debug_Init()
{
	__HAL_UART_ENABLE_IT(&huart5,UART_IT_IDLE);
}
