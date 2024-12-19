#ifndef VOILE_SERVICE_H
#define VOILE_SERVICE_H

#include "stm32f10x.h"
#include "GPIO.h"
#include "Timer.h"
#include "Constantes.h"
#include "ServiceGirouette.h"

void initServoMoteur();

void setPosServoMoteur(int dutycycle);

void controle_voile();


#endif 