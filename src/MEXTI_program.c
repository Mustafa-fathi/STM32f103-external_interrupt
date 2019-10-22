#include "LSTD_TYPES.h"

#include "MEXTI_private.h"

#include "MEXTI_interface.h"

void (*EXTI0_CallBack)(void);
void (*EXTI1_CallBack)(void);

void MEXTI_SetMode(u8 ID,u8 Mode)
{
	/*Argument Validation*/
	if(ID<=18)
	{
		switch(Mode)
		{
			case MEXTI_Mode_RISING : MEXTI -> RTSR |= (1<<ID);break;
			case MEXTI_Mode_FALLING: MEXTI -> FTSR |= (1<<ID);break;
			case MEXTI_Mode_IOC	   : 
			MEXTI -> RTSR |= (1<<ID);
			MEXTI -> FTSR |= (1<<ID);break;
			default:/*To do report error*/break;
		}
	}
}

void MEXTI_Enable(u8 ID)
{
	if(ID<=18)
	{
		MEXTI -> IMR|=(1<<ID);
	}
}

void MEXTI_Disable(u8 ID)
{
	if(ID<=18)
	{
		MEXTI -> IMR&=~(1<<ID);
	}
}



void EXTI0_SetCallBack(void(*ptr)(void))
{
	EXTI0_CallBack = ptr;
}

void EXTI1_SetCallBack(void(*ptr)(void))
{
	EXTI1_CallBack = ptr;
}

void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	MEXTI -> PR |= 1;    /*clear flag*/
	//while(1);   //never exit the interrupt
}

void EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
	MEXTI -> PR |= 2;
	//while(1);
}
