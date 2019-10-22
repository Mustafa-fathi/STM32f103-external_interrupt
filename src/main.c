/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */
#include "LSTD_TYPES.h"

#include "MGPIO_interface.h"

#include "MRCC_interface.h"

#include "MNVK_interface.h"

#include "MEXTI_interface.h"

void EXTI0_Func(void)
{
	MGPIO_SetPin(PORTA,Pin2);
}

void EXTI1_Func(void)
{
	MGPIO_ClearPin(PORTA,Pin2);
}

void main(void)
{
	MRCC_Initialize();
	MRCC_EnableClock(BUS_APB2,PERIPHERAL_GPIOA);
	MRCC_EnableClock(BUS_APB2,PERIPHERAL_AFIO);

	MGPIO_INITIALIZE();

    MGPIO_SetPin(PORTA,0);  //a0 input pull-up
    MGPIO_SetPin(PORTA,1);  //a1 input pull-up


	MNVK_EnableInt(6);
	MNVK_EnableInt(7);
	MNVK_SetPriority();
	MEXTI_SetMode(0,MEXTI_Mode_FALLING);
	MEXTI_SetMode(1,MEXTI_Mode_FALLING);
	//	asm("MOV r0,#1");
	//	asm("MSR PRIMASK,r0");
	EXTI0_SetCallBack(EXTI0_Func);
	EXTI1_SetCallBack(EXTI1_Func);
	MEXTI_Enable(0);
	MEXTI_Enable(1);
	//	MNVK_SetPendingFlag(6);
	while(1)
	{

	}
}
