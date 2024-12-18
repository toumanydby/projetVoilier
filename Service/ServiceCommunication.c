#include "ServiceCommunication.h"
#include "GPIO.h"
#include <stdio.h>

void process_data(int data){
	printf("received data: %d\n", data);
	ourGPIO_struct TestGPIO;
	
	TestGPIO.GPIO = GPIOA;
	TestGPIO.GPIO_pin = 0;
	TestGPIO.GPIO_conf = altOut_Ppull;	
	ourGPIO_Toggle(&TestGPIO, 0);
	
}
void Communication_Config(){
	
	ourGPIO_struct TXGPIO;
	ourGPIO_struct RXGPIO;
	
	TXGPIO.GPIO = GPIOA;
	TXGPIO.GPIO_pin = 5;
	TXGPIO.GPIO_conf = altOut_Ppull;
	
	RXGPIO.GPIO = GPIOA;
	RXGPIO.GPIO_pin = 6;
	RXGPIO.GPIO_conf = in_Floating;
	
	ourGPIO_Init(&TXGPIO);
	ourGPIO_Init(&RXGPIO);
	
	MyUART_Init(USART1,9600);
	MyUART_EnableReceiveInterruption(USART1,getOrientationCap);
}

void getOrientationCap(void){
	int received_data = MyUART_Read(USART1);
	process_data(received_data);
}



//void Communication_Send_AngleVoile(int angle){ 
	//	MyUART_Send(USART1, angle);
//} 

//void Communication_Send_NiveauBaterie(uint8_t niveau_baterie){
	//MyUART
	
//}
//void Communication_Send_LimiteRoulis(char * msg){
	//MyUART_Send(USART1, msg);
	
//}