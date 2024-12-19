#include "USART.h"
void (*PtrFonct) (void);

void USART_Init(USART_TypeDef *USARTx, uint32_t baudrate) {

    if (USARTx == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (USARTx == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (USARTx == USART3) RCC->APB1ENR |= RCC_APB1ENR_USART3EN;

    uint32_t pclk;
    if (USARTx == USART1) pclk = SystemCoreClock / 1;  // APB2
    else pclk = SystemCoreClock / 2;  // APB1
    USARTx->BRR = pclk / baudrate;

    USARTx->CR1 = USART_CR1_TE | USART_CR1_RE; 
    USARTx->CR2 = 0;                          
    USARTx->CR3 = 0;                         

    USARTx->CR1 |= USART_CR1_UE;
		USARTx->CR1 |= (USART_CR1_TE | USART_CR1_RE);
}

void USART_SendChar(USART_TypeDef *USARTx, char c) {
    while (!(USARTx->SR & USART_SR_TXE)); 
    USARTx->DR = c;                       
}

char USART_ReceiveChar(USART_TypeDef *USARTx) {
    while (!(USARTx->SR & USART_SR_RXNE)); 
    return (char)(USARTx->DR & 0xFF);      
}

void USART_EnableInterrupt(USART_TypeDef *USARTx, void (* IT_function) (void)) {
  USARTx->CR1 |= USART_CR1_RXNEIE; 
  if (USARTx == USART1) NVIC_EnableIRQ(USART1_IRQn);
  else if (USARTx == USART2) NVIC_EnableIRQ(USART2_IRQn);
  else if (USARTx == USART3) NVIC_EnableIRQ(USART3_IRQn);
	PtrFonct = IT_function;
}

void USART1_IRQHandler(void) {
    if (USART1->SR & USART_SR_RXNE) { 
      USART1-> SR &= ~USART_SR_RXNE;			
      			(*PtrFonct) ();
		}
}

void USART2_IRQHandler(void) {
    if (USART2->SR & USART_SR_RXNE) { 
      USART2-> SR &= ~USART_SR_RXNE;			
      			(*PtrFonct) ();
		}
}

void USART3_IRQHandler(void) {
    if (USART3->SR & USART_SR_RXNE) {
      USART3->SR &= ~USART_SR_RXNE;			
      			(*PtrFonct) ();
		}
}