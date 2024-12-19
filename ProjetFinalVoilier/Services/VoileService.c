
#include "VoileService.h"

MyTimer_Struct_TypeDef TimerServo;
ourGPIO_struct positionServo; 

void initServoMoteur(){
	
	positionServo.GPIO= GPIO_ServoMoteur;
	positionServo.GPIO_conf=altOut_Ppull;
	positionServo.GPIO_pin= GPIOPin_ServoMoteur;

	//timer PWM pposition Servomotor	
	TimerServo.Timer = TimerServo_Moteur;//20ms
	TimerServo.ARR = (20000-1); //20000
	TimerServo.PSC = (72-1); // 72
	int cycle=75; //
	
	//INIT
	MyTimer_Base_Init(&TimerServo);
	MyTimer_PWM(TimerServo.Timer,Channel_ServoMoteur);
	MyTimer_SetDutyCycle(TimerServo.Timer,Channel_ServoMoteur, cycle);
	MyTimer_Base_Start(TimerServo.Timer);

	ourGPIO_Init(&positionServo);
}


void setPosVoile(int angleGirouette){ //angle que nous retourne girouette.c 
	
	double changement ;
	
	if(angleGirouette < 45){
	changement = 0;
	} else {
		// loi affine 	
		changement = (angleGirouette - 45) / 1.5;
	}
	
	MyTimer_SetDutyCycle(TimerServo.Timer,Channel_ServoMoteur, changement);
}

void controle_voile(){
	int angle_girouette = getAngleGirouette();
	setPosVoile(angle_girouette);
}