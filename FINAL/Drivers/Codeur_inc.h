#ifndef CODEUR_INC_H
#define CODEUR_INC_H

#include "stm32f10x.h"
#include "Constantes.h"
#include "GPIO.h"


/**
 * @brief Initialise le codeur incremental sur un timer specifique
 * 
 * @param Timer timer desire 
 */
void Encoder_Init(TIM_TypeDef * Timer);

/**
 * @brief initialise l'interruption externe pour la broche Z
 * 
 */
void Z_Pin_Interrupt_Init(void);

/**
 * @brief Handler de l'interruption pour EXT1 Line 0
 * 
 * @param Timer timer desire
 */
void EXTI0_IRQHandler(TIM_TypeDef * Timer);

/**
 * @brief Lis la valeur du counter du Timer, en gros lis la valeur du codeur incremental 
 * 
 * @param Timer timer desite 
 * @return uint32_t valeur du conteur 
 */
uint32_t read_encoder_value(TIM_TypeDef * Timer);

#endif 