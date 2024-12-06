#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "stm32f10x.h"
#include "UART.h"

void Communication_Config();
void getOrientationCap(void);
//void Communication_Send_AngleVoile(int angle); //Tous les 3 secondes
//void Communication_Send_NiveauBaterie(uint8_t niveau_baterie);
//void Communication_Send_LimiteRoulis(char * msg);

#endif
