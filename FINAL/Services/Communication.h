#ifndef COMMUNICATION_H
#define COMMUNICATION_H

/**
 * @brief Initialise les configurations pour la communication entre le module X-bee et la carte Nucleo 
 * 
 */
void Communication_Conf();

/**
 * @brief Lis la vitesse communiquee par la telecommande X-bee
 * 
 * @return int vitesse du plateau 
 */
int read_vitesse();

/**
 * @brief Lis le sens communique par la telecommande X-bee
 * 
 * @return int sens du plateau 
 */
int read_sens();

/**
 * @brief Fonction callback appelee lorsqu'une interruption est declenchee donc en gros lorsqu'on donne une nouvelle 
 * vitesse ou un nouveau sens au plateau
 */
void recevoir_info_plateau();
#endif