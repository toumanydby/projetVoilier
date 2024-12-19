#include "CommunicationService.h"

int received_data ;

void getOrientationCap(void){
	received_data = MyUART_Read(USART1);
	MyUART_Send(USART1, received_data);
}

void init_Communication_UART(){
	
	ourGPIO_struct TXGPIO;
	ourGPIO_struct RXGPIO;
	
	TXGPIO.GPIO = GPIO_Xbee_Com;
	TXGPIO.GPIO_pin = GPIOPin_TX;
	TXGPIO.GPIO_conf = altOut_Ppull;
	
	RXGPIO.GPIO = GPIO_Xbee_Com;
	RXGPIO.GPIO_pin = GPIOPin_RX;
	RXGPIO.GPIO_conf = in_Floating;
	
	ourGPIO_Init(&TXGPIO);
	ourGPIO_Init(&RXGPIO);
	
	MyUART_Init(USART1,9600);
	MyUART_EnableReceiveInterruption(USART1,getOrientationCap);
}

void data(void){
	updatePlateauState(received_data);
}