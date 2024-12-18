#include "GPIO.h"

void MyGPIO_Init(GPIO_TypeDef * GPIO, char Pin, char Conf){
	if (GPIO==GPIOA){ RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;}
	else if (GPIO==GPIOB){ RCC->APB2ENR |= (0x01 << 3);}
	else if (GPIO==GPIOC){ RCC->APB2ENR |= (0x01 << 4);}
	else if (GPIO==GPIOD){ RCC->APB2ENR |= (0x01 << 5);}
	
	if (Pin<7){ //Partie CRL
		GPIO->CRL &= ~(0xF << (4*(Pin)));
		GPIO->CRL |= (Conf<<(4*(Pin)));
	}else{ //Partie CRH
		GPIO->CRH &= ~(0xF << (4*(Pin-8)));
		GPIO->CRH |= (Conf<<(4*(Pin-8)));
	}
}
int MyGPIO_Read(GPIO_TypeDef * GPIO, char Pin){
	return GPIO->IDR & 0x01<<Pin;
}
void MyGPIO_Set(GPIO_TypeDef * GPIO, char Pin){
	GPIO->ODR |= 0x01<<Pin;
}


void MyGPIO_Reset(GPIO_TypeDef * GPIO, char Pin){
	GPIO->ODR &= ~(0x01<<Pin);
}


void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char Pin){
	if (MyGPIO_Read(GPIO,Pin)) {
		MyGPIO_Reset(GPIO,Pin);
	}else{
		MyGPIO_Set(GPIO,Pin);	
	}
}