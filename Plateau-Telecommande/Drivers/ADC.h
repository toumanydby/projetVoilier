#ifndef MY_ADC
#define MY_ADC
#include "stm32f10x.h"

void MyADC_Init(ADC_TypeDef * ADC, char voie);
int MyGPIO_Start(ADC_TypeDef * ADC);

#endif