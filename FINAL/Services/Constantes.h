#ifndef CONSTANTES_H
#define CONSTANTES_H

// Plateau 
#define TimerPWM_Plateau TIM2
#define GPIO_Sens_Plateau GPIOA
#define GPIO_Vitesse_Plateau GPIOA
#define GPIOPin_Sens_Plateau 4
#define GPIOPin_Vitesse_Plateau 1
#define Channel_Plateau 2

// Servo Moteur ( Voile )
#define GPIO_ServoMoteur GPIOA
#define GPIOPin_ServoMoteur 7
#define TimerServo_Moteur TIM3
#define Channel_ServoMoteur 2 

// Girouette
#define TimerComIncremental TIM1
#define GPIO_IC1_CodIncr GPIOA
#define GPIOPin_IC1_CodIncr 8
#define GPIO_IC2_CodIncr GPIOA
#define GPIOPin_IC2_CodIncr 9
#define GPIO_Z GPIOA
#define GPIOPin_Z 0

//Telecommande
#define USART_Telecommande USART3
#define GPIO_RX GPIOB
#define GPIOPin_RX 11
#define GPIO_TX GPIOB
#define GPIOPin_TX 10
#define TimerTelecommande TIM2



#endif
