#include "ServiceGirouette.h"



void initGirouette(){
		Encoder_Init(TimerComIncremental);
		Z_Pin_Interrupt_Init();
}


int getAngleGirouette(){
	uint32_t cnt = read_encoder_value(TimerComIncremental);
	int angle = cnt/4;
	
	return angle;
}