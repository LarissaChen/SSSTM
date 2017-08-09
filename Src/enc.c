#include "enc.h"
//2B=1.2 2A=1.1   1A=2.1 1B=2.2   3A=3.1 3B=3.2   4A=4.1 4B=4.2
uint32_t Enc_Channel_A[5]={0,TIM_CHANNEL_1,TIM_CHANNEL_1,TIM_CHANNEL_1,TIM_CHANNEL_1};
uint32_t Enc_Channel_B[5]={0,TIM_CHANNEL_2,TIM_CHANNEL_2,TIM_CHANNEL_2,TIM_CHANNEL_2};
TIM_HandleTypeDef* Enc_Tim[5]={NULL,&htim2,&htim1,&htim3,&htim4};
void Enc_Init()
{
	//结构体定义
	TIM_Encoder_InitTypeDef init;
	init.EncoderMode=TIM_ENCODERMODE_TI12;
	init.IC1Polarity=TIM_ICPOLARITY_BOTHEDGE;
	init.IC1Selection=TIM_ICSELECTION_DIRECTTI;
	init.IC1Prescaler=TIM_ICPSC_DIV1;
	init.IC1Filter=0x00;
	init.IC2Polarity=TIM_ICPOLARITY_BOTHEDGE;
	init.IC2Selection=TIM_ICSELECTION_DIRECTTI;
	init.IC2Prescaler=TIM_ICPSC_DIV1;
	init.IC2Filter=0x00;
	uint8_t encnum;
	for(encnum=1;encnum<=4;encnum++)
	{
		HAL_TIM_Encoder_Init(Enc_Tim[encnum],&init);
		HAL_TIM_Encoder_Start(Enc_Tim[encnum],Enc_Channel_A[encnum]);
		HAL_TIM_Encoder_Start(Enc_Tim[encnum],Enc_Channel_A[encnum]);
	}
}
