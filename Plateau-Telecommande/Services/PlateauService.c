#include "PlateauService.h"
#include "GPIO.h"
#include "Timer.h"
#include "Constantes.h"
#include "USART.h"

//ourGPIO_struct sens ;
//ourGPIO_struct vitesse ;
//MyTimer_Struct_TypeDef TimerPWM;


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
	
	//vitesse.GPIO= GPIO_Vitesse_Plateau;
	//vitesse.GPIO_conf=altOut_Ppull;
	//vitesse.GPIO_pin= GPIOPin_Vitesse_Plateau;
		
	//sens.GPIO= GPIO_Sens_Plateau;
	//sens.GPIO_conf=out_Ppull;
	//sens.GPIO_pin= GPIOPin_Sens_Plateau;
	
	//timer pour PWM, control vitesse
	
	//TimerPWM.Timer = TimerPWM_Plateau; //20kHz 
	//TimerPWM.ARR = (100-1);
	//TimerPWM.PSC = (36-1);
	int cycle=30; //
	
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
				
			}
			else{
				MyGPIO_Reset(GPIO_Sens_Plateau,GPIOPin_Sens_Plateau);
			}
}                                         