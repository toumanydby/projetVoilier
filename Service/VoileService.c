#include "GPIO.h"
#include "TIMER.h"
#include "constantes.h"
#include <stdio.h>


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
	int cycle=50; //
	
	//INIT
	MyTimer_Base_Init(&TimerServo);
	MyTimer_Base_Start(TimerServo.Timer);
	MyTimer_PWM(TimerServo.Timer,Channel_ServoMoteur);
	MyTimer_SetDutyCycle(TimerServo.Timer,Channel_ServoMoteur, cycle);

	ourGPIO_Init(&positionServo);
}


void setPosServoMoteur(int dutycycle){ //nombre entre 1-100
	//1ms-2ms de 20ms -> entre 5 et 10 %
	double changement = dutycycle * 0.05;
	changement +=5;
	MyTimer_SetDutyCycle(TimerServo.Timer,channel, changement);
}