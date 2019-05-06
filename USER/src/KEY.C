/***********************************************************************
�ļ����ƣ�KEY.C
��    �ܣ���������
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺
***********************************************************************/
#include "main.h"

static void Key_Delay(uint32_t nCount);
/***********************************************************************
�������ƣ�Key_Configuration(void)
��    �ܣ����key������
���������
���������
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺key1->PC6,
		  key2->PC7,
		  key3->PC8,
		  key4->PC9,
***********************************************************************/
void Key_Configuration(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	/* Enable the GPIO_KEY Clock */
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
}

/***********************************************************************
�������ƣ�Key_Value(void)
��    �ܣ����ذ�����ֵ
���������
���������������ֵ,,�޼����·���0
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺key1 ��1,
		  key2 ��2,
		  key3 ��3,
		  key4 ��4,
		  �޼�����ʱ���� 0
***********************************************************************/
unsigned char Key_Value(void)
{
	if(KEY1)//KEY1����
	{
		Key_Delay(0XFFFF);//��ʱ����
		if(KEY1)
		{
			return KEY1_VALUE;
		}	
	}
	else
	if(KEY2)//KEY2����
	{
		Key_Delay(0XFFFF);//��ʱ����
		if(KEY2)
		{
			return KEY2_VALUE;
		}	
	}
	else
	if(KEY3)//KEY3����
	{
		Key_Delay(0XFFFF);//��ʱ����
		if(KEY3)
		{
			return KEY3_VALUE;
		}	
	}
	else
	if(KEY4)//KEY4����
	{
		Key_Delay(0XFFFF);//��ʱ����
		if(KEY4)
		{
			return KEY4_VALUE;
		}	
	}
	else	//�޼�����
	{
		return 0;
	}
	return 0;
}



/***********************************************************************
�������ƣ�Key_Delay(uint32_t nCount)
��    �ܣ�����������ʱ
���������
���������
��дʱ�䣺2013.4.25
�� д �ˣ�
ע    �⣺
***********************************************************************/
static void Key_Delay(uint32_t nCount)
{ 
  while(nCount > 0)
  { 
  	  nCount --;   
  }

}