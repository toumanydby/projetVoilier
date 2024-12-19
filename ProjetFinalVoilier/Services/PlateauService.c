#include "PlateauService.h"

ourGPIO_struct sens ;
MyTimer_Struct_TypeDef TimerPWM;

void initPlateau(){
	
	//gpio pour la rotation du plateau
	
	sens.GPIO= GPIO_Sens_Plateau;
	sens.GPIO_conf=out_Ppull;
	sens.GPIO_pin= GPIOPin_Sens_Plateau;
	
	//timer pour PWM, control vitesse
	TimerPWM.Timer = TimerPWM_Plateau; //20kHz 
	TimerPWM.ARR = (100-1);
	TimerPWM.PSC = (36-1);
	int vitesse=75; //
	
	MyTimer_Base_Init(&TimerPWM);
	MyTimer_PWM(TimerPWM.Timer,Channel_Plateau);
	MyTimer_SetDutyCycle(TimerPWM.Timer,Channel_Plateau, vitesse);
	
	//INIT
	ourGPIO_Init(&sens);
}

void startPlateau(){
	MyTimer_Base_Start(TimerPWM.Timer);
}

void updatePlateauState(int i){
	if(i < 128){
		ourGPIO_Reset(&sens,GPIOPin_Sens_Plateau);
	} else {
		ourGPIO_Set(&sens,GPIOPin_Sens_Plateau);
	}
	
	MyTimer_SetDutyCycle(TimerPWM.Timer,Channel_Plateau, i*10);
} 