#include "UART.h"
#include "GPIO.h"
void (*Uart_PTF1) (void);
void (*Uart_PTF2) (void);
void (*Uart_PTF3) (void);


void MyUART_Init(USART_TypeDef *UART, unsigned int debitRate){

	// Frequence in Hz
	int fck;
	
	// Activation de l'horloge en fonction de l'UART
	if(UART == USART1) RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	if(UART == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	if(UART == USART3) RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
	
	if(UART == USART1){
		fck = 72000000;
	} else {
		fck = 36000000;
	}	
	
	// On active notre UART
	// On met le CR1 à USART_CR1_UE qui permet enable notre UART
	UART->CR1 |= USART_CR1_UE;
	// On place ensuite la longueur du mot a envoyer à la valeur USART_CR1_M qui veut dire: 1 Start bit, 9 Data bits, n Stop bit
	UART->CR1 &= ~USART_CR1_M;
	// Efface les bits de stop
	UART->CR2 &= ~USART_CR2_STOP; 
	// Configure l'UART à 1 bit de stop
	//UART->CR2 |= USART_CR2_STOP_0;
	
	// On place maintenant la valeur du debit
	UART->BRR = fck / debitRate;
	
	// On active les flags de reception et de transmission 
	UART->CR1 |= (USART_CR1_RE | USART_CR1_TE);
}

void MyUART_Send(USART_TypeDef *UART, char data){
	// On ne fait rien tant que le flag "transmit data register empty" (USART_SR_TXE) n'est pas set.
	while( !(UART->SR & USART_SR_TXE)){
	}
	// On envoie ensuite les datas dans le registres DR.
	UART->DR = data;	
}

char MyUART_Read(USART_TypeDef *UART){
	// on les lit ensuite
	return UART->DR;
}


void MyUART_EnableReceiveInterruption(USART_TypeDef *UART, void ( * IT_function ) (void)) {
		// On active RXNE avec le flag (Receive Data Register Not Empty) et pour gerer les erreurs on active le flag USART_CR1_PEIE
    UART->CR1 |= (USART_CR1_RXNEIE | USART_CR1_PEIE);
    ourGPIO_struct TX_GPIO;
		// On active l'interruption de l'UART dans le NVIC
		if(UART == USART1){
			Uart_PTF1 = IT_function;
			TX_GPIO.GPIO = GPIOA;
			TX_GPIO.GPIO_conf = altOut_Ppull;
			TX_GPIO.GPIO_pin = 9;
			ourGPIO_Init(&TX_GPIO);
			NVIC_EnableIRQ(USART1_IRQn);
		} 
		else if( UART == USART2){
			Uart_PTF2 = IT_function;
			TX_GPIO.GPIO = GPIOD;
			TX_GPIO.GPIO_conf = altOut_Ppull;
			TX_GPIO.GPIO_pin = 5;
			ourGPIO_Init(&TX_GPIO);
			NVIC_EnableIRQ(USART2_IRQn);
		} 
		else if( UART == USART3){
			TX_GPIO.GPIO = GPIOB;
			TX_GPIO.GPIO_conf = altOut_Ppull;
			TX_GPIO.GPIO_pin = 10;
			ourGPIO_Init(&TX_GPIO);
			Uart_PTF3 = IT_function;
			NVIC_EnableIRQ(USART3_IRQn);
		}
}

void USART1_IRQHandler(void){	
	// Pas besoin de sup le flag RXNE si on faisait USART1->DR cela supp automatiquement le flag, cela n'est pas 
	// notre cas ici donc on reset le flag 
	if(USART1->SR & USART_SR_RXNE) {
		USART1->SR &= ~USART_SR_RXNE;
		(*Uart_PTF1)(); 
	}	
}
 
void USART2_IRQHandler(void){
	if(USART2->SR & USART_SR_RXNE) {
		USART2->SR &= ~USART_SR_RXNE;
    (*Uart_PTF2)(); 
	}
}

void USART3_IRQHandler(void){
	if(USART3->SR & USART_SR_RXNE) {
		USART3->SR &= ~USART_SR_RXNE;
    (*Uart_PTF3)();   
	}
}
