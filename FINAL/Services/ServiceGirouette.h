#ifndef SERVICE_GIROUETTE_H
#define SERVICE_GIROUETTE_H

#include "stm32f10x.h"
#include "GPIO.h"
#include "Codeur_inc.h"
#include "Constantes.h"


/**
 * @brief Initialise les configs de la girouette
 * 
 */
void initGirouette();

/**
 * @brief Recupere l'angle de la girouette compris entre 0 et 360 degres.
 * 
 * @return int valeur de l'angle [0,360]
 */
int getAngleGirouette();

#endif