#ifndef MY_ADC
#define MY_ADC
#include "stm32f10x.h"



/**
 * @brief Initialise l'ADC choisie sur une voie definie
 * 
 * @param ADC ADC selectionnee
 * @param voie voie empruntee
 */
void MyADC_Init(ADC_TypeDef * ADC, char voie);

/**
 * @brief Lance l'ADC et retourne la valeur du registre DR
 * 
 * @param ADC ADC selectionnee
 * @return int valeur du registre DRs
 */
int MyADC_Start(ADC_TypeDef * ADC);

#endif