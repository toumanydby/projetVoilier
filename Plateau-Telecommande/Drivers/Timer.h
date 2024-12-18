#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"

void MyTimer_Base_Init(TIM_TypeDef * Timer, unsigned short PSC, unsigned short ARR);

void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio, void (*ptrFonctionArg) (void));

void MyTimer_PWM(TIM_TypeDef *Timer, char Channel);

void MyTimer_SetDutyCycle(TIM_TypeDef * Timer, char Channel, char dutycycle);


#define MyTimer_Base_Start(Timer) Timer->CR1 |= TIM_CR1_CEN
#define MyTimer_Base_Stop(Timer) Timer->CR1 &= ~(TIM_CR1_CEN)

#endif