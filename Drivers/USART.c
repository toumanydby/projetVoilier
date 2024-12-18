#include "USART.h"
void (*PtrFonct) (void);

void USART_Init(USART_TypeDef *USARTx, uint32_t baudrate) {
    // 1. Activar el reloj del USART
    if (USARTx == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    else if (USARTx == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    else if (USARTx == USART3) RCC->APB1ENR |= RCC_APB1ENR_USART3EN;

    // 2. Configurar la velocidad de transmisión (baud rate)
    uint32_t pclk;
    if (USARTx == USART1) pclk = SystemCoreClock / 1;  // APB2
    else pclk = SystemCoreClock / 2;  // APB1
    USARTx->BRR = pclk / baudrate;

    // 3. Configurar modo de funcionamiento: 8N1 (8 bits de datos, sin paridad, 1 bit de parada)
    USARTx->CR1 = USART_CR1_TE | USART_CR1_RE; // Habilitar transmisión y recepción
    USARTx->CR2 = 0;                           // 1 bit de parada
    USARTx->CR3 = 0;                           // Sin hardware flow control

    // 4. Habilitar el USART
    USARTx->CR1 |= USART_CR1_UE;
		USARTx->CR1 |= (USART_CR1_TE | USART_CR1_RE);
}


void USART_SendChar(USART_TypeDef *USARTx, char c) {
    while (!(USARTx->SR & USART_SR_TXE)); // Esperar a que el registro de transmisión esté vacío
    USARTx->DR = c;                       // Escribir el carácter en el registro de datos
}


char USART_ReceiveChar(USART_TypeDef *USARTx) {
    while (!(USARTx->SR & USART_SR_RXNE)); // Esperar a que el registro de recepción tenga datos
    return (char)(USARTx->DR & 0xFF);      // Leer y devolver el dato recibido
}

void USART_EnableInterrupt(USART_TypeDef *USARTx, void (* IT_function) (void)) {
  USARTx->CR1 |= USART_CR1_RXNEIE; // Habilitar interrupción RXNE
  if (USARTx == USART1) NVIC_EnableIRQ(USART1_IRQn);
  else if (USARTx == USART2) NVIC_EnableIRQ(USART2_IRQn);
  else if (USARTx == USART3) NVIC_EnableIRQ(USART3_IRQn);
	PtrFonct = IT_function;
}




void USART1_IRQHandler(void) {
    if (USART1->SR & USART_SR_RXNE) { // Comprobar si hay datos recibidos
      USART1-> SR &= ~USART_SR_RXNE;			// Procesar el dato
			(*PtrFonct) ();
		}
}

void USART2_IRQHandler(void) {
    if (USART2->SR & USART_SR_RXNE) { // Comprobar si hay datos recibidos
      USART2-> SR &= ~USART_SR_RXNE;			// Procesar el dato
			(*PtrFonct) ();
		}
}

void USART3_IRQHandler(void) {
    if (USART3->SR & USART_SR_RXNE) { // Comprobar si hay datos recibidos
      USART3-> SR &= ~USART_SR_RXNE;			// Procesar el dato
			(*PtrFonct) ();
		}
}