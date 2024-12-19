#ifndef GPIO_H
#define GPIO_H

#include "stm32f10x.h"

typedef struct{
	GPIO_TypeDef * GPIO;
	char GPIO_pin;  // numero de 0 a 15
	char GPIO_conf;	// voir ci dessous 
} ourGPIO_struct;


#define in_Floating 0x04
#define in_PullDown 0x08
#define in_PullUp 0x15 // conf specifique pour le pull up, la diff se fera sur le PxODR register
#define in_Analog 0x00
#define out_Ppull 0x01
#define out_OD 0x05
#define altOut_Ppull 0x09
#define altOut_OD 0x13

void ourGPIO_Init( ourGPIO_struct * GPIOStructPtr);
int ourGPIO_Read( ourGPIO_struct * GPIO, char GPIO_pin ); // renvoie 0 ou autre chose different de 0
void ourGPIO_Set(ourGPIO_struct * GPIO, char GPIO_pin);
void ourGPIO_Reset(ourGPIO_struct * GPIO, char GPIO_pin);
void ourGPIO_Toggle(ourGPIO_struct * GPIO, char GPIO_pin);

#endif