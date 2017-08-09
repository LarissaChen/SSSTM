#include "wmdstep.h"
//��Ϊ�涨 ����Ϊ��
//9.2=step1 11.1=step3 12.2=step4 14.1=step2
//9.1=lun1 10.1=lun3 13.1=lun2 12.1=lun4
static int32_t pre[5]={0};//pre[0]���� תǰ����
static int32_t now[5]={0};//now[0]  ת�����
//��ʹ����챵����Ϊ���������������
TIM_HandleTypeDef* Step_TIM[5]={NULL,&htim9,&htim13,&htim10,&htim12};//��ʱ��
uint32_t Step_Ch[5]={0,TIM_CHANNEL_1,TIM_CHANNEL_1,TIM_CHANNEL_1,TIM_CHANNEL_1};//Ƶ��
GPIO_TypeDef* Step_DIR_Port[5]={NULL,DIR_LUN1_GPIO_Port,DIR_LUN2_GPIO_Port,DIR_LUN3_GPIO_Port,DIR_LUN4_GPIO_Port};
uint16_t Step_DIR_Pin[5]={NULL,DIR_LUN1_Pin,DIR_LUN2_Pin,DIR_LUN3_Pin,DIR_LUN4_Pin};
HAL_StatusTypeDef Step_Init()//�����߸��� ����Ҫ�Ķ�ʱ����Ƶ��
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
HAL_StatusTypeDef Step_Set(uint8_t motornum,int32_t step)//step������
{
	
	uint32_t ch=Step_Ch[motornum];
	TIM_HandleTypeDef* tim=Step_TIM[motornum];
	now[motornum]+=step;//��������������
	if(step<0)HAL_GPIO_WritePin(Step_DIR_Port[motornum],Step_DIR_Pin[motornum],GPIO_PIN_RESET);//������� 
	else HAL_GPIO_WritePin(Step_DIR_Port[motornum],Step_DIR_Pin[motornum],GPIO_PIN_SET);
	HAL_Delay(1);//����ʱ���õ����Ӧ
	return HAL_TIM_PWM_Start_IT(tim,ch);
}
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	uint8_t motornum=1;
	for(;motornum<=4;motornum++)
	{
		if(Step_TIM[motornum]==htim)break;
	}
	if(now[motornum]-pre[motornum]>0)//��ת���
		pre[motornum]++;
	else if(now[motornum]-pre[motornum]<0)//��ת���
		pre[motornum]--;
	else //���ת��
		HAL_TIM_PWM_Stop_IT(Step_TIM[motornum],Step_Ch[motornum]);
}
