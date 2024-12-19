#ifndef CONSTANTES_H
#define CONSTANTES_H

// Plateau 
#define TimerPWM_Plateau TIM2
#define GPIO_Sens_Plateau GPIOA
#define GPIOPin_Sens_Plateau 2
#define Channel_Plateau 2


// Servo Moteur ( Voile )
#define GPIO_ServoMoteur GPIOA
#define GPIOPin_ServoMoteur 7
#define TimerServo_Moteur TIM3
#define Channel_ServoMoteur 2 

// Module X-bee Communication 
#define USART_Xbee USART3
#define GPIO_Xbee_Com GPIOB
#define GPIOPin_TX 10
#define GPIOPin_RX 11

// Girouette
#define TimerComIncremental TIM1
#define GPIO_IC1_CodIncr GPIOA
#define GPIOPin_IC1_CodIncr 8
#define GPIO_IC2_CodIncr GPIOA
#define GPIOPin_IC2_CodIncr 9

#endif