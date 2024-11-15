#include "stm32f10x.h"
#include "GPIO.h"


ourGPIO_struct btnPoussoir;
ourGPIO_struct led;

void testGPIO(){
	ourGPIO_struct gpioA;
	ourGPIO_struct gpioB;
	ourGPIO_struct gpioC;
	ourGPIO_struct gpioD;
	
	gpioA.GPIO = GPIOB;
	gpioA.GPIO_pin = 0;
	gpioA.GPIO_conf = in_Floating;
	
	gpioB.GPIO = GPIOA;
	gpioB.GPIO_pin = 7;
	gpioB.GPIO_conf = in_PullDown;
	
	gpioC.GPIO = GPIOA;
	gpioC.GPIO_pin = 15;
	gpioC.GPIO_conf = in_PullUp;
	
	gpioD.GPIO = GPIOB;
	gpioD.GPIO_pin = 4;
	gpioD.GPIO_conf = in_Analog;
	
	ourGPIO_Init(&gpioA);
	ourGPIO_Init(&gpioB);
	ourGPIO_Init(&gpioC);
	ourGPIO_Init(&gpioD);

}
int main ( void )
{
	
		//User button -->	PC13 
	//User LD2: the green LED is connected to PA5 (pin 21) or PB13 (pin 34)
//	GPIOA->CRL &= ~(0xF) ;										
//	GPIOA->CRL |= (0x1) ;

//	//configuration bouton poussoir pull down
//	GPIOC->CRH &= ~(0xF) ; //Effacer les bits de configuration
//	GPIOC->CRH |= (0x4) ;
	
	//	do 
//	{
//		//lire l'etat du bouton poussoir PC8
//		if ((GPIOC->IDR & (1 << 8) )==0) {
//            // Si bouton appuyé, allumer la LED (PA0)
//            GPIOA->BSRR = (1 << 0);  // Mettre PA0 à HIGH
//        } else {
//            // Si bouton relâché, éteindre la LED
//            GPIOA->BRR = (1 << 0);   // Mettre PA0 à LOW
//        }					
//	} while (1);
	
	//testGPIO();
	
	btnPoussoir.GPIO = GPIOC;
  btnPoussoir.GPIO_pin = 8;
  btnPoussoir.GPIO_conf = in_PullDown;

	led.GPIO = GPIOA;
	led.GPIO_pin = 0;
	led.GPIO_conf = out_Ppull;
	
	ourGPIO_Init( &btnPoussoir);			
	ourGPIO_Init( &led);
	
	do{
			if(ourGPIO_Read( &btnPoussoir,btnPoussoir.GPIO_pin)){
				ourGPIO_Set(&led,led.GPIO_pin);
			} else{
				ourGPIO_Reset(&led,led.GPIO_pin);
			}
	}while(1);	
}

