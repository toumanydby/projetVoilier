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