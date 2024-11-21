#include "stm32f10x.h"
#include "GPIO.h"
#include "TIMER.h"
#include "codeur_inc.h"

/*void Callback(void){
		GPIOA->ODR ^= GPIO_ODR_ODR0;  // Toggle la broche PA0
	}
*/


int main ( void )
{
	/*
	//RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	//TIM2->PSC |= 36000 ;
	//TIM2->ARR |= 1000 ;

	ourGPIO_struct ledTest;
	
	ledTest.GPIO = GPIOA;
	ledTest.GPIO_pin = 0;
	ledTest.GPIO_conf = out_Ppull;
	
	ourGPIO_Init(&ledTest);
	
	MyTimer_Struct_TypeDef Timer2_500ms;
	Timer2_500ms.Timer = TIM2;
	Timer2_500ms.ARR = 1000;
	Timer2_500ms.PSC = 36000;
	MyTimer_Base_Init(&Timer2_500ms);
	MyTimer_Base_Start(TIM2);
	MyTimer_ActiveIT(TIM2,2,Callback);
	
	Periode_Timer = ARR * Periode_Compteur
	Periode_Compteur = PSC * Periode_PSC
	Donc Periode_Timer = ARR * PSC * Periode_PSC

	On a Frequence_PSC = 72e6 Hz
	Donc Periode_PSC = 1/(72e6) s
	
	On veut Periode_Timer = 500 ms
	Donc ARR*PSC = 36e6
	Une solution possible : (ARR;PSC) = (1000;36000)
	
	
	//0xA2C8 = 1010 0010 1100 1000
	
	*/
	
	Encoder_Init(TIM1);
	
	
	
	
}
