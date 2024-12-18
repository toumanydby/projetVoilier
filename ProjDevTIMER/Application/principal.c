/*#include "stm32f10x.h"
#include "GPIO.h"
#include "TIMER.h"
#include "codeur_inc.h"
*/
/*void Callback(void){
		GPIOA->ODR ^= GPIO_ODR_ODR0;  // Toggle la broche PA0
	}
*/
/*

int main ( void )
{
	
	Encoder_Init(TIM1);
	Z_Pin_Interrupt_Init();
	
	while (1){}
	
	
}*/

#include "stm32f10x.h"
#include "GPIO.h"
#include "TIMER.h"
#include "UART.h"
#include <stdio.h>
#include "ServiceCommunication.h"


int main() {
    Communication_Config();
		//MyUART_Send(USART1, 'H');
	
    
    while (1) {
        // Wait for data reception via interrupt
    }
}
