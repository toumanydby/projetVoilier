#include "PlateauService.h"
#include "GPIO.h"
#include "TIMER.h"
#include "constantes.h"
#include "UART.h"

ourGPIO_struct sens ;
ourGPIO_struct vitesse ;
MyTimer_Struct_TypeDef TimerPWM;


// int received_data;

// void Receive(void){
// 	received_data = MyUART_Read(USART1);
// 	MyUART_Send(USART1, received_data);
// }


// void UsartInit(void){
// 	Uart_init(USART1,9600);
	
// 	MyGPIO_Init(GPIOA,9,altOut_Ppull);//tx
// 	MyGPIO_Init(GPIOA,10,In_Floating);//rx
	  
//   //MyGPIO_Init(GPIOA, 5, Out_Ppull);// 
	
// 	MyUART_EnableReceiveInterruption(USART1,UART_Callback);

// 	Receive_Interruption(USART1,8,Receive);	
// }


void initPlateau(){
	
	//gpio pour la rotation du plateau, bit sens et vitesse
	
	vitesse.GPIO= GPIO_Vitesse_Plateau;
	vitesse.GPIO_conf=altOut_Ppull;
	vitesse.GPIO_pin= GPIOPin_Vitesse_Plateau;
		
	sens.GPIO= GPIO_Sens_Plateau;
	sens.GPIO_conf=out_Ppull;
	sens.GPIO_pin= GPIOPin_Sens_Plateau;
	
	//timer pour PWM, control vitesse
	
	TimerPWM.Timer = TimerPWM_Plateau; //20kHz 
	TimerPWM.ARR = (100-1);
	TimerPWM.PSC = (36-1);
	int cycle=20; //
	
	MyTimer_Base_Init(&TimerPWM);
	MyTimer_Base_Start(TimerPWM.Timer);
	MyTimer_PWM(TimerPWM.Timer,Channel_Plateau);
	MyTimer_SetDutyCycle(TimerPWM.Timer,Channel_Plateau, cycle);
	
	//INIT
	ourGPIO_Init(&sens);
	ourGPIO_Init(&vitesse);
}


void controlVitesse(int cycle){
			MyTimer_SetDutyCycle(TimerPWM.Timer,channel, cycle);
}