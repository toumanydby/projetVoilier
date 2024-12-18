#include "Timer.h"

void (*ptrFonct) ();

void MyTimer_Base_Init(TIM_TypeDef * Timer, unsigned short PSC, unsigned short ARR){
	if (Timer == TIM1){ RCC->APB2ENR |= RCC_APB2ENR_TIM1EN ;}
	else if (Timer == TIM2){ RCC->APB1ENR |= RCC_APB1ENR_TIM2EN ;}
	else if (Timer == TIM3){ RCC->APB1ENR |= RCC_APB1ENR_TIM3EN ;}
	else if (Timer == TIM4){ RCC->APB1ENR |= RCC_APB1ENR_TIM4EN ;}
	
	Timer->PSC = PSC-1;
	Timer->ARR = ARR-1;
}

void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio, void (*ptrFonctionArg) (void)){
	Timer->DIER |= TIM_DIER_UIE; //Enable interruptions
	if (Timer == TIM1){ 
		NVIC_EnableIRQ(TIM1_UP_IRQn);
		NVIC_SetPriority(TIM1_UP_IRQn, Prio);
	}
	else if (Timer == TIM2){ 
		NVIC_EnableIRQ(TIM2_IRQn);
		NVIC_SetPriority(TIM2_IRQn, Prio);
	}
	else if (Timer == TIM3){ 
		NVIC_EnableIRQ(TIM3_IRQn);
		NVIC_SetPriority(TIM3_IRQn, Prio);
	}
	else if (Timer == TIM4){ 
		NVIC_EnableIRQ(TIM4_IRQn);
		NVIC_SetPriority(TIM4_IRQn, Prio);
	}	
	ptrFonct = ptrFonctionArg;
}


void TIM1_UP_IRQHandler(void){
	if(ptrFonct != 0){
		(*ptrFonct) ();}
	TIM1->SR &= ~(TIM_SR_UIF);
}

void TIM2_IRQHandler(void){
	if(ptrFonct != 0){
		(*ptrFonct) ();}
	TIM2->SR &= ~(TIM_SR_UIF);
}

void TIM3_IRQHandler(void){
	if(ptrFonct != 0){
		(*ptrFonct) ();}
	TIM3->SR &= ~(TIM_SR_UIF);
}

void TIM4_IRQHandler(void){
	if(ptrFonct != 0){
		(*ptrFonct) ();}
	TIM4->SR &= ~(TIM_SR_UIF);
}


void MyTimer_PWM(TIM_TypeDef *Timer, char Channel){
	if (Channel == 1){ 
		Timer->CCMR1 &= ~TIM_CCMR1_OC1M;
		Timer->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
		//Equivalent à : Timer->CCMR1 |= (0x6 << 4) Sert a regler le mode PWM 1
		Timer->CCMR1 |= TIM_CCMR1_OC1PE; //Enable TIM_CCR1
		Timer->CCER |= TIM_CCER_CC1E; //Enables channel 1
	}
	else if (Channel == 2){ 
		Timer->CCMR1 &= ~TIM_CCMR1_OC2M;
		Timer->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
		//Equivalent à : Timer->CCMR1 |= (0x6 << 12) Sert a regler le mode PWM 1
		Timer->CCMR1 |= TIM_CCMR1_OC2PE; //Enable TIM_CCR1
		Timer->CCER |= TIM_CCER_CC2E; //Enables channel 1
	}
	else if (Channel == 3){ 
		Timer->CCMR2 &= ~TIM_CCMR2_OC3M;
		Timer->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;
		//Equivalent à : Timer->CCMR2 |= (0x6 << 4) Sert a regler le mode PWM 1
		Timer->CCMR2 |= TIM_CCMR2_OC3PE; //Enable TIM_CCR1
		Timer->CCER |= TIM_CCER_CC3E; //Enables channel 1
	}
	else if (Channel == 4){ 
		Timer->CCMR2 &= ~TIM_CCMR2_OC4M;
		Timer->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2;
		//Equivalent à : Timer->CCMR2 |= (0x6 << 12) Sert a regler le mode PWM 1
		Timer->CCMR2 |= TIM_CCMR2_OC4PE; //Enable TIM_CCR1
		Timer->CCER |= TIM_CCER_CC4E; //Enables channel 1
	}	
}



void MyTimer_SetDutyCycle(TIM_TypeDef * Timer, char Channel, char dutycycle){
	double pulse = (dutycycle*(Timer->ARR+1))/100;
	
	if (Channel == 1){ 
		Timer->CCR1 = pulse;
	}
	else if (Channel == 2){ 
		Timer->CCR2 = pulse;
	}
	else if (Channel == 3){ 
		Timer->CCR3 = pulse;
	}
	else if (Channel == 4){ 
		Timer->CCR4 = pulse;
	}	
}


