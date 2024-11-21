#ifndef CODEUR_INC_H
#define CODEUR_INC_H

#include "stm32f10x.h"

// Function to initialize the encoder on the specified timer
void Encoder_Init(TIM_TypeDef * Timer);

// Function to initialize the external interrupt for the Z pin
void Z_Pin_Interrupt_Init(void);

// Interrupt handler for EXTI line 0
void EXTI0_IRQHandler(void);

#endif // CODEUR_INC_H