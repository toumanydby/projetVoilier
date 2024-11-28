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
	
	ourGPIO_struct IC1;
	ourGPIO_struct IC2;
	
	IC1.GPIO= GPIOA;
	IC1.GPIO_conf = in_Floating;
	IC1.GPIO_pin = 8;
	
	IC2.GPIO = GPIOA;
	IC2.GPIO_conf = in_Floating;
	IC2.GPIO_pin = 9;
	
	ourGPIO_Init(&IC1);
	ourGPIO_Init(&IC2);
	
	Encoder_Init(TIM1);
	Z_Pin_Interrupt_Init();
	
	while (1){}
	
	
}
