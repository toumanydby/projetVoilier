#ifndef TIMER_H
#define TIMER_H

#include "stm32f10x.h"


typedef struct {
	TIM_TypeDef * Timer; // TIM1 a TIM4
	unsigned short ARR;
	unsigned short PSC;
} MyTimer_Struct_TypeDef;

/**
* @brief 
*			@param -> param sous forme d'une struct ( addresse ) contenant les infos de base
*			@Note -> Fonction a lancer systematiquement avant d'aller plus en detail dans les conf plus fines (PWN, codeur inc ...)
*/
void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Timer);

/**
* @brief 
*			@param : - TIM_TypeDef * Timer : Timer concerne
*							 - char Prio : de 0 a 15
*			@note: La fonction MyTimer_Base_Init dois avoir etre lancee au prealable
*/
void MyTimer_ActiveIT ( TIM_TypeDef * Timer, char Prio, void ( * IT_function ) (void));
void MyTimer_PWM( TIM_TypeDef * Timer , char Channel);
void MyTimer_SetDutyCycle(TIM_TypeDef * Timer, char Channel, int dutycycle);


void TIM1_UP_IRQHandler(void);
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);


#define MyTimer_Base_Start(Timer) Timer->CR1 |= TIM_CR1_CEN
#define MyTimer_Base_Stop(Timer) Timer->CR1 &= ~(TIM_CR1_CEN)

#endif
