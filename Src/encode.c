#include "encode.h"
#include "tim.h"
int32_t code[5]={0};

void Encode_Init(void)
{
	TIM_Encoder_InitTypeDef sEncoderConfig;
  sEncoderConfig.EncoderMode        =  TIM_ENCODERMODE_TI12;
  sEncoderConfig.IC1Polarity        = TIM_ICPOLARITY_RISING;   
  sEncoderConfig.IC1Selection       = TIM_ICSELECTION_DIRECTTI;
  sEncoderConfig.IC1Prescaler       = TIM_ICPSC_DIV1; 
  sEncoderConfig.IC1Filter          = 0;
  
  sEncoderConfig.IC2Polarity        = TIM_ICPOLARITY_RISING;   
  sEncoderConfig.IC2Selection       = TIM_ICSELECTION_DIRECTTI;  
  sEncoderConfig.IC2Prescaler       = TIM_ICPSC_DIV1; 
  sEncoderConfig.IC2Filter          = 0;
		
 

		HAL_TIM_Encoder_Init(&htim2,&sEncoderConfig);//encode1 tim2  ch1 ch2
	  HAL_TIM_Encoder_Init(&htim1,&sEncoderConfig);//encode2 tim2  ch1 ch2
	  HAL_TIM_Encoder_Init(&htim3,&sEncoderConfig);//encode3 tim2  ch1 ch2
	  HAL_TIM_Encoder_Init(&htim4,&sEncoderConfig);//encode4 tim2  ch1 ch2
	
	
		  HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_2);
			
			HAL_TIM_Encoder_Start(&htim1,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Start(&htim1,TIM_CHANNEL_2);
			
		  HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_2);
			
			
		  HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_1);
			HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_2);
		
			
		   TIM2->CNT = 0;
			 TIM1->CNT = 0;
			 TIM3->CNT = 0;
			 TIM4->CNT = 0;





}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin==GPIO_PIN_15)   //ENCODE1   zÏà¹éÁã
	{
		 TIM2->CNT = 0;
			

	}
		
		
		
		
		
	if(GPIO_Pin==GPIO_PIN_12)   //ENCODE2
	{
		 
			 TIM1->CNT = 0;
			

	}
		
		
		
		
		
		
if(GPIO_Pin==GPIO_PIN_3)   //ENCODE3
	{
		 
			 TIM3->CNT = 0;
		
	}
		
		
		
		
		
		
if(GPIO_Pin==GPIO_PIN_11)   //ENCODE4
	{
		
			 TIM4->CNT = 0;

	}
		
		
	
		
}
void Encode_f5(void)
{
	code[1]=TIM2->CNT/4;
	code[2]=TIM1->CNT/4;
	code[3]=TIM3->CNT/4;
	code[4]=TIM4->CNT/4;
}
