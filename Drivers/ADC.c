#include "ADC.h"


void OurADC_Init(ourADC_struct * ADCStructPtr){
	if (ADCStructPtr->ADC == ADC1){
		// On active l'horloge
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	}else if (ADCStructPtr->ADC == ADC2){
		// On active l'horloge
		RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
	}
	// diviser la fréq par 6 au niveau du RCC   12MHz
	RCC-> CFGR &=~ RCC_CFGR_ADCPRE;
	RCC-> CFGR|= RCC_CFGR_ADCPRE_DIV6;
	
	// On active l'ADC
	ADCStructPtr->ADC->CR2 |= ADC_CR2_ADON;

	
	// Configure le sample timing of the canal 10 en 28.5 cicles
	ADCStructPtr->ADC->SMPR1 = 0; 
	
	// On configure la voie Canal 10 en entré principal
	ADCStructPtr->ADC->SQR3 = ADCStructPtr->ADC_voie;

	//SINGLE NOT CONTINUOS MODE
	ADCStructPtr->ADC->CR2 &= ~ADC_CR2_CONT;

	// étalonner l'ADC (Calibrar)
	ADCStructPtr->ADC->CR2 |= ADC_CR2_CAL; // Init
	while (ADCStructPtr->ADC->CR2 & ADC_CR2_CAL); // Wait

	/* valider ext trig*/
	ADCStructPtr->ADC->CR2 |= ADC_CR2_EXTTRIG;
	ADCStructPtr->ADC->CR2 |= ADC_CR2_EXTSEL;
	
}


void OurADC_Start(ourADC_struct * ADCStructPtr){
	
	ADCStructPtr->ADC->CR2 |= ADC_CR2_SWSTART;//commencer la conversion
	
	// attend 
	while (!(ADCStructPtr->ADC->SR & ADC_SR_EOC)) {}
	
}