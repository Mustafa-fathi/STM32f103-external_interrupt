#ifndef _MEXTI_INTERFACE_H
#define _MEXTI_INTERFACE_H

#define MEXTI_Mode_RISING	1
#define MEXTI_Mode_FALLING	2
#define MEXTI_Mode_IOC		3

void MEXTI_SetMode(u8 ID,u8 Mode);

void MEXTI_Enable(u8 ID);

void MEXTI_Disable(u8 ID);

void EXTI0_SetCallBack(void(*ptr)(void));

void EXTI1_SetCallBack(void(*ptr)(void));

#endif
