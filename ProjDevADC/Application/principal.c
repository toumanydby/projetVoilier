#include "stm32f10x.h"
#include "GPIO.h"
#include "TIMER.h"
#include "ADC.h"

volatile int adcValue;
int main ( void ) {
ourADC_struct ADCStructPtr;
	ADCStructPtr.ADC = ADC1;
	ADCStructPtr.ADC_voie = 10;
	
	OurADC_Init(&ADCStructPtr);
	
	OurADC_Start(&ADCStructPtr);
	
}
	
	
