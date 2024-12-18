#include "stm32f10x.h"
#include "GPIO.h"

int main ( void )
{
	//RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	
	//GPIOA->CRL &= ~(0xF<<4) ;
	//GPIOA->CRL |= (0x2<<4) ;
	
	//Boutton poussoir PC13 floating input
	//RCC->APB2ENR |= (0x01 << 4); //On active l'horloge de GPIOC
	//GPIOC->CRH &= ~(0xF << (4*(13-8)));  //On met a 0 tous les bits des registres CNF13 et MODE13 
	//GPIOC->CRH |= GPIO_CRH_CNF13;
	//GPIOC->CRH |= (0x4<<(4*(13-8))); //On met 01 dans CNF13 et 00 dans MODE13 (on aura 0 pour tout le reste) (on trouve la valeur grace a la table)
	
	//LED Verte PA5 output push pull
	//RCC->APB2ENR |= (0x01 << 2); //On active l'horloge de GPIOC
	//GPIOA->CRL &= ~(0xF << (4*(5)));  //On met a 0 tous les bits des registres CNF13 et MODE13 
	//GPIOC->CRH |= GPIO_CRH_CNF13;
	//GPIOA->CRL |= (0x1<<(4*(5)));
	
	MyGPIO_Init(GPIOA, 5, In_Floatting);
	MyGPIO_Init(GPIOC, 13, Out_Ppull);
	
	
	while (1)
	{
		if (MyGPIO_Read(GPIOA, 5)){
		MyGPIO_Set(GPIOC,13);
	}else{
		MyGPIO_Reset(GPIOC,13);
	}
	}
}
