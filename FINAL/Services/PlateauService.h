#ifndef PLATEAU_SERVCICE_H
#define PLATEAU_SERVCICE_H

#include "stm32f10x.h"

void initPlateau();

void controlVitesse(int cycle);
void controlSens(char sens);


#endif