#ifndef MYUSART_H
#define MYUSART_H
#include "stm32f10x.h"


/**
 * @brief Initialise l'USART choisie avec un debit choisi ( en bauds )
 * 
 * @param USARTx USART selectionnee
 * @param baudrate debit en bauds
 */
void USART_Init(USART_TypeDef *USARTx, uint32_t baudrate);

/**
 * @brief Envoie un caractere c a travers l'USART donc l'ecrit  
 * 
 * @param USARTx USART choisie 
 * @param c caractere a envoyer
 */
void USART_SendChar(USART_TypeDef *USARTx, char c);

/**
 * @brief Recoie un caractere donc le lit et le retourne
 * 
 * @param USARTx USART choisie
 * @return char caractere lu
 */
char USART_ReceiveChar(USART_TypeDef *USARTx);

/**
 * @brief Active l'interruption de l'USART et specifie la fonction callback a effectuer
 * 
 * @param USARTx USART choisie 
 * @param IT_function fonction callback a effectuer
 */
void USART_EnableInterrupt(USART_TypeDef *USARTx, void (* IT_function) (void));

#endif