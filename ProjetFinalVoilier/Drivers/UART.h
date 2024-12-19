#ifndef UART_H
#define UART_H

#include "stm32f10x.h"


/**
* @brief 
*			@param -> - USART_TypeDef *UART : USART concerne
*							  - unsigned int debitRate: debit en bauds
*			@Note -> Fonction d'initialisation de l'USART
*/
void MyUART_Init(USART_TypeDef *UART, unsigned int debitRate);


/**
* @brief 
*				@params -> - USART_TypeDef *UART: UART voulu
*									 - char data: data a envoyer
*				@note -> Send the char data to the desired UART
*/
void MyUART_Send (USART_TypeDef *UART, char data);

/**
* @brief 
*				@params -> - USART_TypeDef *UART: UART voulu
*				@note -> Return the UART->BR value
*/
char MyUART_Read(USART_TypeDef *UART);


void MyUART_EnableReceiveInterruption(USART_TypeDef *UART, void ( * IT_function ) (void));

#endif
