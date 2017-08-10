#include "lun.h"


#define TIMEOUT 50
HAL_StatusTypeDef Motorcommand(uint8_t motornum,uint8_t* command,uint8_t size)//对指定电机发送指令
{
	UART_HandleTypeDef* motoruart;
	//目前使用向量命名法命名电机
	switch(motornum)
	{
		case 1:motoruart=&huart2;break;
		case 2:motoruart=&huart3;break;
		case 3:motoruart=&huart6;break;
		case 4:motoruart=&huart4;break;
		default:return HAL_ERROR;
	}
	HAL_UART_Transmit(motoruart,command,size,TIMEOUT);
	command[1]=0xFF;
	HAL_UART_Receive(motoruart,command,2,TIMEOUT);
	if(command[1]==command[0])
		return HAL_OK;
	else return HAL_ERROR;
}

HAL_StatusTypeDef Motor_Start(uint8_t motornum)//电机启动
{
	uint8_t send[4]={0,0,1,1};
	return Motorcommand(motornum,send,4);
}
HAL_StatusTypeDef Motor_Stop(uint8_t motornum)//电机停止
{
	uint8_t send[4]={0,0,0,0};
	return Motorcommand(motornum,send,4);
}
HAL_StatusTypeDef Motor_Speed_Enable(uint8_t motornum)//速度模式控制启用
{
	uint8_t send[4]={0x02,0x00,0xc4,0xc6};
	return Motorcommand(motornum,send,4);
}
HAL_StatusTypeDef Motor_Speed_Add(uint8_t motornum,double speed)//加减速度中加速度
{
	uint8_t u8speed=(uint8_t)(speed/24.0);//通过技术文档进行的换算
	uint8_t send[4]={0x0a,speed,0x00,speed+0x0a};
	return Motorcommand(motornum,send,4);
}
void Motor_Init(uint8_t motornum)//装载轮毂电机 根据需要修改
{
	Motor_Speed_Enable(motornum);
	HAL_Delay(100);
	//Motor_Start(motornum);
	HAL_Delay(100);
	//Motorcommand(motornum,(uint8_t*)"\x1d\x01\x2c\x4A",4);//设定最大速度为300
	HAL_Delay(100);
}

HAL_StatusTypeDef Motor_Speed_Set(uint8_t motornum,int16_t speed)//设定旋转速度 输入量为RPM
{
	int16_t speeddata=(int16_t)(speed*2.73);//根据技术手册将RPM换成相应数据
	uint8_t high=speeddata & 0xFF00;
	uint8_t low= speeddata & 0XFF;
	uint8_t mix=high+low+0x06;
	uint8_t send[4]={0x06,high,low,mix};
	return Motorcommand(motornum,send,4);
}
HAL_StatusTypeDef Motor_Clear_Error(uint8_t motornum)//异常状态位清除 谨慎使用
{
	uint8_t send[4]={0x4a,0x00,0x00,0x4a};
	return Motorcommand(motornum,send,4);
}
//HAL_StatusTypeDef Motor_Clear_Error(uint8_t motornum)

