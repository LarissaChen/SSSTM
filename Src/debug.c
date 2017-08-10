#include "debug.h"
#include "wmdstep.h"
#include "lun.h"
#include "stm32f4xx_hal_uart.h"
static uint8_t motornum=0;//1234Ϊ��� 5678Ϊ(x-4)�Ų���
static uint8_t buffer=0;
/*����Э��
0x01~0x08 ѡ���Ӧ���
0x10 ��Ӧ���ת��
0x11 ��Ӧ�����ת
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
			if(motornum>4)return Step_Set(motornum-4,400);//�ٶȰ������
				else return Motor_Speed_Set(motornum,50);
		case 0x11:
			if(motornum>4)return Step_Set(motornum-4,-400);//�ٶȰ������
				else return Motor_Speed_Set(motornum,-50);
		
		
	}
	return HAL_ERROR;
}
HAL_StatusTypeDef Debug_Init(void)
{
	HAL_UART_Receive_IT(&huart5,&buffer,1);
	return HAL_OK;//�˴�δ�����趨������ķ���ֵ
}
