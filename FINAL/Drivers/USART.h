#ifndef MYUSART_H
#define MYUSART_H
#include "stm32f10x.h"


void USART_Init(USART_TypeDef *USARTx, uint32_t baudrate);
void USART_SendChar(USART_TypeDef *USARTx, char c);
char USART_ReceiveChar(USART_TypeDef *USARTx);
void USART_EnableInterrupt(USART_TypeDef *USARTx, void (* IT_function) (void));

#endif