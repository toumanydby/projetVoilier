#ifndef VOILE_SERVICE_H
#define VOILE_SERVICE_H

#include "stm32f10x.h"
#include "GPIO.h"
#include "Timer.h"
#include "Constantes.h"
#include "ServiceGirouette.h"

/**
 * @brief Initialise le servo moteur des voiles 
 * 
 */
void initServoMoteur();

/**
 * @brief Attribue une nouvelle postion au servo moteur en fonction de l'angle de la girouette
 * 
 * @param angleGirouette valeur de l'angle retournee par la girouette
 */
void setPosVoile(int angleGirouette);

/**
 * @brief Permet de controler la voile quand on a une nouvelle position des voiles a placer ( quand on a une nouvelle valeur de 
 * l'angle de girouette )
 */
void controle_voile();


#endif 