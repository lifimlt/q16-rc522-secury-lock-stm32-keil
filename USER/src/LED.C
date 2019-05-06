/***********************************************************************
�ļ����ƣ�LED.C
��    �ܣ�led  IO��ʼ��
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺
***********************************************************************/
#include "main.h"

static void LED_Delay(uint32_t nCount);
/***********************************************************************
�������ƣ�LED_Configuration(void)
��    �ܣ����LED������
���������
���������
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺LED1->PE2,
		  LED2->PE3,
		  LED3->PE4,
		  LED4->PE5,
***********************************************************************/
void LED_Configuration(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	/* Enable the GPIO_LED Clock */
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOE , ENABLE); 						 
			
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	/*====LED-OFF=======*/ 
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;
}

/***********************************************************************
�������ƣ�LED_Blink(void)
��    �ܣ����LED��˸
���������
���������
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺
***********************************************************************/
void LED_Blink(void)
{
	LED1_ON;
	LED2_ON;
	LED3_ON;
	LED4_ON;
	LED_Delay(0xfffff);
	LED_Delay(0xfffff);
	/*====LED-OFF=======*/ 
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;
	LED_Delay(0xfffff);
	LED_Delay(0xfffff); 
}
/***********************************************************************
�������ƣ�One_LED_ON(unsigned char led_num)
��    �ܣ�ʵ�ֵ���һ��LED��
���������
���������
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺
***********************************************************************/
void One_LED_ON(unsigned char led_num)
{	
	/*****Ϩ���ĸ�led��******/
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;
	switch(led_num)
	{
		case 1:
		{
			LED1_ON;
			break;
		}
		case 2:
		{
			LED2_ON;
			break;		
		}
		case 3:
		{
			LED3_ON;
			break;		
		}
		case 4:
		{
			LED4_ON;
			break;		
		}
		default:
		{
			break;	
		}
	}		
}

void One_LED_OFF(unsigned char led_num)
{	
	/*****Ϩ���ĸ�led��******/

	switch(led_num)
	{
		case 1:
		{
			LED1_OFF;
			break;
		}
		case 2:
		{
			LED2_OFF;
			break;		
		}
		case 3:
		{
			LED3_OFF;
			break;		
		}
		case 4:
		{
			LED4_OFF;
			break;		
		}
		default:
		{
			break;	
		}
	}		
}



static void LED_Delay(uint32_t nCount)
{ 
  while(nCount > 0)
  { 
  	  nCount --;   
  }
}