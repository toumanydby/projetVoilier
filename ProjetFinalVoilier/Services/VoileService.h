#ifndef VOILE_SERVICE_H
#define VOILE_SERVICE_H

#include "stm32f10x.h"
#include "GPIO.h"
#include "TIMER.h"
#include "constantes.h"
#include "ServiceGirouette.h"

/**
* @brief initialise le servo moteur des voiles ( pwm )
*	@param
*	@Note 
*/
void initServoMoteur();

/**
* @brief attribue au servo moteur un nouvel angle ( une nouvelle position)
* en fontion de la valeur de l'angle de la girouette
*	@param angleGirouette, angle obtenue du codeur incremental
*	@Note 
*/
void setPosVoile(int angleGirouette);


/**
* @brief recupere l'angle du codeur incremental et l'attribue pour le nouvel angle des voiles
*	@param
*	@Note 
*/
void controle_voile();

#endif 