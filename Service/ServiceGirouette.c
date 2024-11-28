#include "ServiceGirouette.h"
#include "GPIO.h"
#include "codeur_inc.h"
#include "constantes.h"



int getAngleGirouette(){
	Encoder_Init(TimerComIncremental);
	Z_Pin_Interrupt_Init();
	uint32_t cnt = read_encoder_value(TimerComIncremental);
	int angle = cnt/4;
	
	return angle;
}
