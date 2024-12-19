#ifndef PLATEAU_SERVCICE_H
#define PLATEAU_SERVCICE_H

#include "stm32f10x.h"

/**
 * @brief Initialise et configure le plateau qui fait tourner le voilier
 * 
 */
void initPlateau();

/**
 * @brief ajuste la vitesse du plateau en fonction de la valeur de cycle 
 * 
 * @param cycle valeur obtenue depuis la telecommande X-bee
 */
void controlVitesse(int cycle);

/**
 * @brief ajuste le sens du plateau en fonction du caractere sens  
 * 
 * @param sens sens 1 ou 0 pour gauche ou droite 
 */
void controlSens(char sens);

#endif