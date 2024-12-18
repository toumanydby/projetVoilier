#include "Communication.h"
#include "USART.h"
#include "GPIO.h"
#include "Timer.h"
#include <stdlib.h>
#include <stdio.h>

int data;
int vitesse;
char sens;

void recevoir_info_plateau(){
	data = USART_ReceiveChar(USART1);
		if (data<=100 && data >= 0){
			vitesse = data;
			sens = 0;
		}else if (256 >= data && data >= 156){
			vitesse = abs(data - 256);
			sens = 1;
		}
	
	//if (abs(received_data <= 100)) {
	//		data = received_data;
  //}
}

int read_vitesse(){
	return vitesse;
}

int read_sens(){
	return sens;
}


void send_angle(){
	//USART_SendChar(USART1, angle);
}


void Communication_Conf(){
	MyGPIO_Init(GPIOA, 10, In_Floatting);
	MyGPIO_Init(GPIOA, 9, Out_Ppull);
	USART_Init(USART1, 9600);
	USART_EnableInterrupt(USART1, recevoir_info_plateau);
	
	//MyTimer_Base_Init(TIM3, 7200, 30000);
	//MyTimer_ActiveIT(TIM3, 3, send_angle);
}

