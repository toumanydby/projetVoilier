#include "stm32f10x.h"
#include "GPIO.h"
#include "TIMER.h"
#include "UART.h"
#include <stdio.h>

void Callback(void){
GPIOA->ODR ^= GPIO_ODR_ODR0; 
}

void UART_Callback(void) {
	int received_data;
	received_data = MyUART_Read(USART1);
	GPIOA->ODR ^= GPIO_ODR_ODR0;  // Toggle la broche PA0
	MyUART_Send(USART1,received_data);
}

int main() {
    // Initialize UART with a 9600 baud rate
    MyUART_Init(USART1, 9600);
    // Enable receive interrupt for USART1
    MyUART_EnableReceiveInterruption(USART1,UART_Callback);

    // Send test data
    MyUART_Send(USART1, 'H');  // Expect 'H' to appear in the terminal
//    MyUART_Send(USART1, 'i');  // Expect 'i' to appear in the terminal
    
    while (1) {
        // Wait for data reception via interrupt
    }
}