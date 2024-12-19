#include "GPIO.h"

void ourGPIO_Init( ourGPIO_struct * GPIOStructPtr){
	
	if(GPIOStructPtr->GPIO == GPIOA) RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;//(0x01 << 2);
	if(GPIOStructPtr->GPIO == GPIOB) RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;//(0x01 << 3);
	if(GPIOStructPtr->GPIO == GPIOC) RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;//(0x01 << 4);
	if(GPIOStructPtr->GPIO == GPIOD) RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;//(0x01 << 5);
	
	char pin = GPIOStructPtr->GPIO_pin;
	char conf = GPIOStructPtr->GPIO_conf;
	
	// cas CRL
	if( pin <= 7) {
		 	
		GPIOStructPtr->GPIO->CRL &= ~(0x0F << 4 * pin);

		if( conf == 0x15){
				conf = 0x08;
				GPIOStructPtr->GPIO->ODR |= (0x01 << pin);
		}
		else{
				GPIOStructPtr->GPIO->ODR |= (0x00 << pin);			
		}
		
		GPIOStructPtr->GPIO->CRL |= (conf <<  4 * pin);
	}
	// cas CRH
	else{
		GPIOStructPtr->GPIO->CRH &= ~(0x0F << 4 * (pin - 8)); // le registre CRH est utilise pour les pin de 8 a 15 donc la pin 8 est a la position 0 , la 9 a la 1 etc pour le registre CRH 

		if( conf == 0x15){
				conf = 0x08;
				GPIOStructPtr->GPIO->ODR |= (0x01 << pin);
		}
		else{
				GPIOStructPtr->GPIO->ODR |= (0x00 << pin);			
		}
		
		GPIOStructPtr->GPIO->CRH |= (conf <<  4 * (pin - 8));
	}
}


/**
* Ici on cherche a lire l'etat input de notre GPIO, donc ce qu'il faut faire c'est comparé la valeur du GPIO a la bonne broche 
* a la valeur de 1 decale de la valeur de la pin
*
*/
int ourGPIO_Read( ourGPIO_struct * GPIOStructPtr, char GPIO_pin ){
	if( (GPIOStructPtr->GPIO->IDR & (0x01 << GPIO_pin)) == (0x01 << GPIO_pin)){
		return 1;
	} 
	return 0;
}

/**
* On cherche a mettre a jour la valeur du GPIO sur la bonne pin donc on utilise le registre BSRR
*/
void ourGPIO_Set(ourGPIO_struct * GPIOStructPtr, char GPIO_pin){
	GPIOStructPtr->GPIO->BSRR |= (0x01 << GPIO_pin);
}


/**
* On cherche a reset la valeur du GPIO sur la bonne pin donc on utilise le registre BRR
*/
void ourGPIO_Reset(ourGPIO_struct * GPIOStructPtr, char GPIO_pin){
	GPIOStructPtr->GPIO->BRR |= (0x01 << GPIO_pin);
}

/**
* On cherche a inverser la valeur du GPIO sur la bonne pin donc on utilise le registre BSRR
*/
void ourGPIO_Toggle(ourGPIO_struct * GPIOStructPtr, char GPIO_pin){
	GPIOStructPtr->GPIO->BRR ^= (0x01 << GPIO_pin);
}