#include "VoileService.h"
#include "GPIO.h"
#include "TIMER.h"
#include "constantes.h"

ourGPIO_struct positionServo;
MyTimer_Struct_TypeDef TimerServo;
int channel;

void initServo(){
	positionServo.GPIO= GPIO_ServoMoteur;
	positionServo.GPIO_conf=altOut_Ppull;
	positionServo.GPIO_pin= GPIOPin_ServoMoteur;

	
	//timer PWM pposition Servomotor
	
	TimerServo.Timer = TimerServo_Moteur;//20ms
	TimerServo.ARR = (20000-1);
	TimerServo.PSC = (72-1);
	int cycle=50; //
	
	//INIT
	
	ourGPIO_Init(&positionServo);
	
	MyTimer_Base_Init(&TimerServo);
	MyTimer_PWM(TimerServo.Timer,Channel_ServoMoteur);
	MyTimer_SetDutyCycle(TimerServo.Timer,Channel_ServoMoteur, cycle); //100 = Voile rabattue, 50 = Voile ouverte
	MyTimer_Base_Start(TimerServo.Timer);

}

void setPositionServo(int dutycycle){//nombre entre 1-100
	//1ms-2ms de 20ms -> entre 5 et 10 %
	double changement = dutycycle; //= dudycycle * 2 /100;
	//changement +=5;
	
	MyTimer_SetDutyCycle(TimerServo.Timer,Channel_ServoMoteur, changement);
}

/*

void Voile_Set(int angle){
	
	int pwm;
	
	if (angle<=180) {
		pwm = 100 - ((50*angle)/180);
	}else if (angle <=360){
		pwm = (50*angle)/180;
	}
	
	MyTimer_SetDutyCycle(TimerServo.Timer,Channel_ServoMoteur,pwm);	
}
*/