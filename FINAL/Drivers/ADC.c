#include "ADC.h"

void MyADC_Init(ADC_TypeDef * ADC, char voie){
	if (ADC==ADC1){RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;}
	else if (ADC==ADC2){RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;}
	
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6;  //On divise la frequence de clksystem par 6 pour avoir <= 14Mhz
	ADC->CR2 |= ADC_CR2_ADON;   //Validation ADC
	ADC->CR2 &= ~ADC_CR2_CONT;   //Configuration ADC en mode SINGLE NOT CONTINU
	
	//if (voie < 10){
		//ADC->SMPR2 |= (0b001 << (3*voie));   //On met le temps d'ouverture de la fenetre au minimum (On peut le changer, consulter manuel)
	//}else{
		//ADC->SMPR1 |= (0b001) << (3*(10-voie));
	//}
	ADC->SQR3 = voie;  //On met dans la 1ere conversion la valeur de notre voie

	ADC->CR2 |= ADC_CR2_CAL;   //Calibrer l'ADC
	while(ADC->CR2 & ADC_CR2_CAL);  //Attendre � la bone calibration
	
	ADC->CR2 |= ADC_CR2_EXTTRIG;
	ADC->CR2 |= ADC_CR2_EXTSEL;
}

int MyADC_Start(ADC_TypeDef * ADC){
	ADC->CR2 |= ADC_CR2_SWSTART; //commencer la conversion
	while(!(ADC1->SR & ADC_SR_EOC));
	return ADC->DR;
}