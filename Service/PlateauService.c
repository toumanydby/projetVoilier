#include "PlateauService.h"
#include "GPIO.h"
#include "TIMER.h"
#include "constantes.h"

ourGPIO_struct sens ;
ourGPIO_struct vitesse ;
MyTimer_Struct_TypeDef TimerPWM;
int channel;


void initPlateau(){
	
	//gpio pour la rotation du plateau, bit sens et vitesse
	
	vitesse.GPIO= GPIO_Vitesse_Plateau;
	vitesse.GPIO_conf=altOut_Ppull;
	vitesse.GPIO_pin= 1;
		
	sens.GPIO= GPIOA;
	sens.GPIO_conf=out_Ppull;
	sens.GPIO_pin= 2;
	
	//timer pour PWM, control vitesse
	
	TimerPWM.Timer = TIM2;//20kHz 
	TimerPWM.ARR = (100-1);
	TimerPWM.PSC = (36-1);
	channel=2;
	int cycle=20; //
	
	
	MyTimer_Base_Init(&TimerPWM);
	MyTimer_Base_Start(TimerPWM.Timer);
	MyTimer_PWM(TimerPWM.Timer,channel);

	MyTimer_SetDutyCycle(TimerPWM.Timer,channel, cycle);
	
	//INIT
	
	ourGPIO_Init(&sens);
	ourGPIO_Init(&vitesse);
	
}

void controlVitesse(int cycle){
			MyTimer_SetDutyCycle(TimerPWM.Timer,channel, cycle);
}