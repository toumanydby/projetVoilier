#ifndef COMMUNICATION_SERVICE_H
#define COMMUNICATION_SERVICE_H

#include "stm32f10x.h"
#include "GPIO.h"
#include "constantes.h"
#include "UART.h"
#include "PlateauService.h"

/**
* @brief  Initialise l'uart nous permettant de communiquer avec le module X-bee
*	@param
*	@Note 
*/
void init_Communication_UART();

/**
* @brief Recupere l'orientation et la vitesse que le plateau doit prendre depuis le module X-bee
*	@param
*	@Note 
*/
void getOrientationCap(void);


/**
* @brief Utiliser pour mettre a jour la position et la vitesse du plateau quand on recoit une data de
* la part du module x-bee
*	@param
*	@Note 
*/
void data(void);

#endif 