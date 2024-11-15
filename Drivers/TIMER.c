#include "TIMER.h"

void (*PTF1) (void);
void (*PTF2) (void);
void (*PTF3) (void);
void (*PTF4) (void);

void MyTimer_Base_Init(MyTimer_Struct_TypeDef * TimIN){
	if(TimIN->Timer == TIM1) RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	if(TimIN->Timer == TIM2) RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	if(TimIN->Timer == TIM3) RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	if(TimIN->Timer == TIM4) RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	
	TimIN->Timer->ARR |= TimIN->ARR;
	TimIN->Timer->PSC |= TimIN->PSC;
}

void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio, void ( * IT_function ) (void)){
	
	Timer->DIER |= TIM_DIER_UIE; // TIM_DIER_UIE : bit d'activation de l'IT 
	
	if (Timer == TIM1){
		PTF1 = IT_function;
		NVIC_EnableIRQ(TIM1_UP_IRQn);
		NVIC_SetPriority(TIM1_UP_IRQn,Prio);
	} else if (Timer == TIM2){
		PTF2 = IT_function;
		NVIC_EnableIRQ(TIM2_IRQn);
		NVIC_SetPriority(TIM2_IRQn,Prio);
	} else if (Timer == TIM3){
		PTF3 = IT_function;
		NVIC_EnableIRQ(TIM3_IRQn);
		NVIC_SetPriority(TIM3_IRQn,Prio);
	} else if (Timer == TIM4){
		PTF4 = IT_function;
		NVIC_EnableIRQ(TIM4_IRQn);
		NVIC_SetPriority(TIM4_IRQn,Prio);
	} 
}

void TIM1_UP_IRQHandler(void){
	if(TIM1->SR & TIM_SR_UIF){ // TIM_SR_UIF update Interrupt flag
		TIM1->SR &= ~TIM_SR_UIF; // on reset le flag a zero
		(*PTF1)();
	}
}

void TIM2_IRQHandler(void){
	if(TIM2->SR & TIM_SR_UIF){ // TIM_SR_UIF update Interrupt flag
		TIM2->SR &= ~TIM_SR_UIF; // on reset le flag
		(*PTF2)();
	}
}

void TIM3_IRQHandler(void){
	if(TIM3->SR & TIM_SR_UIF){ // TIM_SR_UIF update Interrupt flag
		TIM3->SR &= ~TIM_SR_UIF; // on reset le flag
		(*PTF3)();
	}
}

void TIM4_IRQHandler(void){
	if(TIM4->SR & TIM_SR_UIF){ // TIM_SR_UIF update Interrupt flag
		TIM4->SR &= ~TIM_SR_UIF; // on reset le flag
		(*PTF4)();
	}
}




