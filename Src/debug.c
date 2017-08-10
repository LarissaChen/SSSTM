#include "debug.h"
#include "wmdstep.h"
#include "lun.h"
#include "stm32f4xx_hal_uart.h"
static uint8_t motornum=0;//1234为轮毂 5678为(x-4)号步进
static uint8_t buffer=0;
/*调试协议
0x01~0x08 选择对应电机
0x10 对应电机转动
0x11 对应电机反转
*/
HAL_StatusTypeDef Debug_Handle(void)
{
	if(buffer==0)
	{
		printf("zero....\n");
		return HAL_ERROR;
	}
	if(buffer<=0x08)
	{
		motornum=buffer;
		return HAL_OK;
	}
	switch(buffer)
	{
		case 0x10:
			if(motornum>4)return Step_Set(motornum-4,400);//速度按需更改
				else return Motor_Speed_Set(motornum,50);
		case 0x11:
			if(motornum>4)return Step_Set(motornum-4,-400);//速度按需更改
				else return Motor_Speed_Set(motornum,-50);
		
		
	}
	return HAL_ERROR;
}
HAL_StatusTypeDef Debug_Init(void)
{
	HAL_UART_Receive_IT(&huart5,&buffer,1);
	return HAL_OK;//此处未真正设定有意义的返回值
}
