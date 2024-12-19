#include "VoileService.h"


void initServoMoteur(){
	MyGPIO_Init(GPIO_ServoMoteur,GPIOPin_ServoMoteur, AltOut_Ppull);
	//timer PWM pposition Servomotor	
	MyTimer_Base_Init(TimerServo_Moteur,72,20000);
	int cycle=50;
	
	//INIT
	MyTimer_Base_Start(TimerServo_Moteur);
	MyTimer_PWM(TimerServo_Moteur,Channel_ServoMoteur);
	MyTimer_SetDutyCycle(TimerServo_Moteur,Channel_ServoMoteur, cycle);

}


void setPosVoile(int angleGirouette){ //angle que nous retourne girouette.c 
	
	double changement ;
	
	if(angleGirouette < 45){
	changement = 0;
	} else {
		// loi affine 	
		changement = (angleGirouette - 45) / 1.5;
	}
	
	MyTimer_SetDutyCycle(TimerServo_Moteur,Channel_ServoMoteur, changement);
}


void controle_voile(){
	int angle_girouette = getAngleGirouette();
	setPosVoile(angle_girouette);
}