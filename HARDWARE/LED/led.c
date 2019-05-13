#include "stm32f10x.h"
#include "led.h"

//��ʼ��PB5��PB6Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PA�˿�ʱ��	
	
	GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_15|GPIO_Pin_14);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,(GPIO_Pin_15|GPIO_Pin_14));	//PA.8 �����
}





