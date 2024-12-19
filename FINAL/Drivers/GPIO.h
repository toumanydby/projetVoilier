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

/**
 * @brief Initialise le GPIO sur une pin donnee avec une config donnee 
 * 
 * @param GPIO GPIO voulu 
 * @param Pin pin desiree 
 * @param Conf  configuration In_Floatting ou autre chose
 */
void MyGPIO_Init(GPIO_TypeDef * GPIO, char Pin, char Conf);

/**
 * @brief Lis la valeur du GPIO sur une pin donnee soit 0 ou 1 
 * 
 * @param GPIO GPIO a lire
 * @param Pin pin voulue
 * @return int 0 ou 1 0 pour la pin non activee 1 sinon
 */
int MyGPIO_Read(GPIO_TypeDef * GPIO, char Pin); 

/**
 * @brief Met la pin du GPIO desire a 1
 * 
 * @param GPIO GPIO desiree
 * @param Pin pin voulue
 */
void MyGPIO_Set(GPIO_TypeDef * GPIO, char Pin);

/**
 * @brief Met la pin du GPIO desire a 0
 * 
 * @param GPIO GPIO desire
 * @param Pin pin voulue
 */
void MyGPIO_Reset(GPIO_TypeDef * GPIO, char Pin); 

/**
 * @brief Inverse le status de la pin
 * 
 * @param GPIO GPIO voulu 
 * @param Pin pin desireee
 */
void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char Pin);

#endif