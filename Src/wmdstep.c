#include "wmdstep.h"
//人为规定 上拉为正
//9.2=step1 11.1=step3 12.2=step4 14.1=step2
//9.1=lun1 10.1=lun3 13.1=lun2 12.1=lun4
static int32_t pre[5]={0};//pre[0]不用 转前参数
static int32_t now[5]={0};//now[0]  转后参数
//现使用轮毂电机作为步进电机的驱动口
TIM_HandleTypeDef* Step_TIM[5]={NULL,&htim9,&htim13,&htim10,&htim12};//定时器
uint32_t Step_Ch[5]={0,TIM_CHANNEL_1,TIM_CHANNEL_1,TIM_CHANNEL_1,TIM_CHANNEL_1};//频道
GPIO_TypeDef* Step_DIR_Port[5]={NULL,DIR_LUN1_GPIO_Port,DIR_LUN2_GPIO_Port,DIR_LUN3_GPIO_Port,DIR_LUN4_GPIO_Port};
uint16_t Step_DIR_Pin[5]={NULL,DIR_LUN1_Pin,DIR_LUN2_Pin,DIR_LUN3_Pin,DIR_LUN4_Pin};
HAL_StatusTypeDef Step_Init()//若排线更换 则需要改定时器与频道
{
	//uint8_t motornum=1;
	
		TIM9->CCR1=500;
		TIM10->CCR1=500;
		TIM13->CCR1=500;
		TIM12->CCR1=500;
	/*
	for(;motornum<=4;motornum++)
	{
		HAL_TIM_Base_Start_IT(Step_TIM[motornum]);
	}
	*/
	
	return HAL_OK;
}
HAL_StatusTypeDef Step_Set(uint8_t motornum,int32_t step)//step步长差
{
	
	uint32_t ch=Step_Ch[motornum];
	TIM_HandleTypeDef* tim=Step_TIM[motornum];
	now[motornum]+=step;//设置启动步长差
	if(step<0)HAL_GPIO_WritePin(Step_DIR_Port[motornum],Step_DIR_Pin[motornum],GPIO_PIN_RESET);//方向决定 
	else HAL_GPIO_WritePin(Step_DIR_Port[motornum],Step_DIR_Pin[motornum],GPIO_PIN_SET);
	HAL_Delay(1);//给出时间让电机反应
	return HAL_TIM_PWM_Start_IT(tim,ch);
}
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	uint8_t motornum=1;
	for(;motornum<=4;motornum++)
	{
		if(Step_TIM[motornum]==htim)break;
	}
	if(now[motornum]-pre[motornum]>0)//正转情况
		pre[motornum]++;
	else if(now[motornum]-pre[motornum]<0)//反转情况
		pre[motornum]--;
	else //完成转动
		HAL_TIM_PWM_Stop_IT(Step_TIM[motornum],Step_Ch[motornum]);
}
