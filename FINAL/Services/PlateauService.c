#include "PlateauService.h"
#include "GPIO.h"
#include "Timer.h"
#include "Constantes.h"
#include "USART.h"

void initPlateau(){
	int cycle = 30;
	MyTimer_Base_Init(TimerPWM_Plateau, 100, 36);
	MyTimer_Base_Start(TimerPWM_Plateau);
	MyTimer_PWM(TimerPWM_Plateau,Channel_Plateau);
	MyTimer_SetDutyCycle(TimerPWM_Plateau,Channel_Plateau, cycle);
	
	//INIT
	MyGPIO_Init(GPIO_Sens_Plateau, GPIOPin_Sens_Plateau, Out_Ppull);
	MyGPIO_Init(GPIO_Vitesse_Plateau, GPIOPin_Vitesse_Plateau, AltOut_Ppull );
	
}


void controlVitesse(int cycle){
	MyTimer_SetDutyCycle(TimerPWM_Plateau,Channel_Plateau, cycle);
}


void controlSens(char sens){
	if(sens){
		MyGPIO_Set(GPIO_Sens_Plateau,GPIOPin_Sens_Plateau);
	}else{
		MyGPIO_Reset(GPIO_Sens_Plateau,GPIOPin_Sens_Plateau);
	}
}



