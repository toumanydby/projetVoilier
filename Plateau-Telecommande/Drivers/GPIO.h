#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"

#define In_Floatting 0x4
#define In_PullDown 0x8
#define In_PullUp 0x8
#define In_Analog 0x0
#define Out_Ppull 0x1
#define Out_OD 0x5
#define AltOut_Ppull 0x9
#define AltOut_OD 0xD

void MyGPIO_Init(GPIO_TypeDef * GPIO, char Pin, char Conf);
int MyGPIO_Read(GPIO_TypeDef * GPIO, char Pin); //Lire la valeur
void MyGPIO_Set(GPIO_TypeDef * GPIO, char Pin); //Mettre le pin a 1
void MyGPIO_Reset(GPIO_TypeDef * GPIO, char Pin); //Mettre la pin a 0
void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char Pin); //Inverser la pin

#endif