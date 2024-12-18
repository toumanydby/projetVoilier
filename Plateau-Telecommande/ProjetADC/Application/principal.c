#include "stm32f10x.h"
#include "GPIO.h"
#include "Timer.h"

void Callback(void){
	MyGPIO_Toggle(GPIOC,13);
}



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
	
	//MyGPIO_Init(GPIOA, 5, In_Floatting);
	//MyGPIO_Init(GPIOC, 13, Out_Ppull);
	
	//RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	//int PSC = 36000 - 1;
	//int ARR = 500-1;
	
	//TIM2->ARR = ARR; //Les registres ARR et PSC sont uniquement des valeur
	//TIM2->PSC = PSC;
	//TIM2->CR1 |= TIM_CR1_CEN;
	
	//MyGPIO_Init(GPIOC, 13, Out_Ppull);
	
	MyGPIO_Init(GPIOA,0,AltOut_Ppull);
	
	MyTimer_Base_Init(TIM2, 72, 10);
	
	MyTimer_PWM(TIM2, 1);
	MyTimer_SetDutyCycle(TIM2,1, 20);
	//MyTimer_ActiveIT(TIM2, 5, Callback);
	MyTimer_Base_Start(TIM2);
	while (1)
	{
		//if (MyGPIO_Read(GPIOA, 5)){
			//MyGPIO_Set(GPIOC,13);
		//}else{
			//MyGPIO_Reset(GPIOC,13);
		//}
	}
}
