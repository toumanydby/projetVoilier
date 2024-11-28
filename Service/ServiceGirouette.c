#include "ServiceGirouette.h"
#include "GPIO.h"
#include "codeur_inc.h"



int getAngleGirouette(){
	Encoder_Init(TIM1);
	Z_Pin_Interrupt_Init();
	uint32_t cnt = read_encoder_value(TIM1);
	int angle = cnt/4;
	
	return angle;
}
