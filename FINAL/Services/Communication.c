#include "Communication.h"
#include "USART.h"
#include "GPIO.h"
#include "Timer.h"
#include <stdlib.h>
#include <stdio.h>
#include "Constantes.h"

int data;
int vitesse;
char sens;

void recevoir_info_plateau(){
	data = USART_ReceiveChar(USART_Telecommande);
		if (data<=100 && data >= 0){
			vitesse = data;
			sens = 0;
		}else if (256 >= data && data >= 156){
			vitesse = abs(data - 256);
			sens = 1;
		}
}

int read_vitesse(){
	return vitesse;
}

int read_sens(){
	return sens;
}

void Communication_Conf(){
	MyGPIO_Init(GPIO_RX, GPIOPin_RX, In_Floatting);
	MyGPIO_Init(GPIO_TX, GPIOPin_TX, AltOut_Ppull);
	USART_Init(USART_Telecommande, 9600);
	USART_EnableInterrupt(USART_Telecommande, recevoir_info_plateau);
}


