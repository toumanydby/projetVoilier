#include "stm32f10x.h"
#include "GPIO.h"
#include "TIMER.h"
#include <stdio.h>

ourGPIO_struct sens ;
ourGPIO_struct vitesse ;
MyTimer_Struct_TypeDef TimerPWM, TimerServo;


ourGPIO_struct positionServo;
 
int channel;
void initPlateau(){
	
	//gpio pour la rotation du plateau, bit sens et vitesse
	
	vitesse.GPIO= GPIOA;
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


void initServo(){
	positionServo.GPIO= GPIOB;
	positionServo.GPIO_conf=altOut_Ppull;
	positionServo.GPIO_pin= 1;

	
	//timer PWM pposition Servomotor
	
	TimerServo.Timer = TIM3;//20ms
	TimerServo.ARR = (20000-1);
	TimerServo.PSC = (72-1);
	channel=2;
	int cycle=50; //
	
		//INIT
	
	ourGPIO_Init(&positionServo);
	
	MyTimer_Base_Init(&TimerServo);
	MyTimer_Base_Start(TimerServo.Timer);
	MyTimer_PWM(TimerServo.Timer,channel);

	MyTimer_SetDutyCycle(TimerServo.Timer,channel, cycle);

	
}



void controlVitesse(int cycle){
			MyTimer_SetDutyCycle(TimerPWM.Timer,channel, cycle);
}

void posServo(int dudycycle){//nombre entre 1-100
	//1ms-2ms de 20ms -> entre 5 et 10 %
	double changement =dudycycle; //= dudycycle * 2 /100;
	//changement +=5;
	
	MyTimer_SetDutyCycle(TimerServo.Timer,channel, changement);
}
int var;
int main() {
    initPlateau();
		initServo();
		var=20;	
    while (1) {
        // Wait for data reception via interrupt
			controlVitesse(var);
			posServo(var);
			
	
		//wait 1 sec 
			
			//controlVitesse(60);
					//wait 1 sec 
			
    }
}