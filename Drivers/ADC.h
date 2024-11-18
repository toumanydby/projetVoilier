#ifndef ADC_H
#define ADC_H

#include "stm32f10x.h"

typedef struct{
	ADC_TypeDef * ADC;
	char ADC_voie;  // numero de 0 a 15
} ourADC_struct;

void OurADC_Init(ourADC_struct * ADCStructPtr);
void OurADC_Start(ourADC_struct * ADCStructPtr);

#endif