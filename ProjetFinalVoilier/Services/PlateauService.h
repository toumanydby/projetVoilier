#ifndef PLATEAU_SERVCICE_H
#define PLATEAU_SERVCICE_H

#include "stm32f10x.h"
#include "GPIO.h"
#include "TIMER.h"
#include "constantes.h"

/**
* @brief Initilise les differenrs composants du plateau 
*	@param
*	@Note 
*/
void initPlateau();

/**
* @brief Met a jour le plateau, sens de rotation et vitesse a laquelle elle doit tourner
*	@param i valeur obtenue du module X-bee
*	@Note 
*/
void updatePlateauState(int i);


/**
* @brief Lance le plateau pour qu'il commence a tourner
*	@param 
*	@Note 
*/
void startPlateau();

#endif
