#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"

/**
* @brief Initialise le timer Timer 
* @param -> TIM_TypeDef * Timer : timer utilise,
*        ->  unsigned short PSC : valeur du prescaler,
*        -> unsigned short ARR : valeur de l'autoreload
* @Note -> Fonction a lancer systematiquement avant d'aller plus en detail dans les conf plus fines (PWN, codeur inc ...)
*/
void MyTimer_Base_Init(TIM_TypeDef * Timer, unsigned short PSC, unsigned short ARR);

/**
* @brief 
* @param : - TIM_TypeDef * Timer : Timer concerne
*		   - char Prio : de 0 a 15
* @note: La fonction MyTimer_Base_Init dois avoir etre lancee au prealable
*/
void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio, void (*ptrFonctionArg) (void));

/**
 * @brief Configure une pwn sur un timer et un canal donne
 * 
 * @param Timer timer sur lequel la pwm est lancee
 * @param Channel canal utilise pour la pwm
 */
void MyTimer_PWM(TIM_TypeDef *Timer, char Channel);

/**
 * @brief Confugure le rapport cyclique de la pwm 
 * 
 * @param Timer timer utilise pour la pwm
 * @param Channel canal utilise
 * @param dutycycle rapport cyclique voulu
 */
void MyTimer_SetDutyCycle(TIM_TypeDef * Timer, char Channel, char dutycycle);


// Lance le timer
#define MyTimer_Base_Start(Timer) Timer->CR1 |= TIM_CR1_CEN

// Arrete le timer
#define MyTimer_Base_Stop(Timer) Timer->CR1 &= ~(TIM_CR1_CEN)

#endif