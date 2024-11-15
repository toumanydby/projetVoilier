#include "stm32f10x.h"
#include "GPIO.h"
#include "TIMER.h"

volatile int adcValue;
int main ( void )
	
{
	// On va utiliser le ADC12_IN10 - pin PC0
ourGPIO_struct ADCPin;
ADCPin.GPIO = GPIOC;
ADCPin.GPIO_pin = 0;
ADCPin.GPIO_conf = in_Analog;
ourGPIO_Init(&ADCPin);

// On active l'horloge
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	// diviser la fréq par 6 au niveau du RCC   12MHz
	RCC-> CFGR &=~ RCC_CFGR_ADCPRE;
	RCC-> CFGR|= RCC_CFGR_ADCPRE_DIV6; 

	

	
	
// Reset
ADC1->CR1 = 0;

// On active l'ADC
ADC1->CR2 |= ADC_CR2_ADON;

	
// Configure le sample timing of the canal 10 en 28.5 cicles
ADC1->SMPR1 = 0; //(0 << 0)|(0 << 1); //
// On configure le Canal 10 en entré principal
ADC1->SQR3 = 10;

//SINGLE NOT CONTINUOS MODE
ADC1->CR2 &= ~ADC_CR2_CONT;

// étalonner l'ADC (Calibrar)
ADC1->CR2 |= ADC_CR2_CAL; // Init
while (ADC1->CR2 & ADC_CR2_CAL); // Wait

/* valider ext trig*/
ADC1->CR2 |= ADC_CR2_EXTTRIG;

while(1)
{
	// lancement conv
	ADC1->CR2 |= ADC_CR2_SWSTART;//commencer la conversqtion
	
	// attend 
	while (!(ADC1->SR & ADC_SR_EOC)) {}
		
  adcValue= ADC1->DR;//lire
}
// ADC1->DR;


	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
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
	*/
	
	//0xA2C8 = 1010 0010 1100 1000*/
}
