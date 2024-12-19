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
	
	TimIN->Timer->ARR = TimIN->ARR;
	TimIN->Timer->PSC = TimIN->PSC;
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

void MyTimer_PWM( TIM_TypeDef * Timer , char Channel){
	
	if(Channel==1){
		Timer->CCMR1 &= ~TIM_CCMR1_OC1M;          // Effacer les bits du mode de comparaison
		Timer->CCMR1 |= (0x6 << 4);  // Regler le mode PWM 1 (0x6)
		Timer->CCMR1 |= TIM_CCMR1_OC1PE;          // Activer le pr chargement pour la comparaison
		Timer->CCER |= TIM_CCER_CC1E;             // Activer la capture/comparaison pour le canal 1 (activer le canal 1 )
	}
	if(Channel==2){
		Timer->CCMR1 &= ~TIM_CCMR1_OC2M;          // Effacer les bits du mode de comparaison
		Timer->CCMR1 |= (0x6 << 12);  // R gler le mode PWM 1 (0x6)
		Timer->CCMR1 |= TIM_CCMR1_OC2PE;          // Activer le pr chargement pour la comparaison
		Timer->CCER |= TIM_CCER_CC2E;             // Activer la capture/comparaison pour le canal 2 (activer le canal 2 )
	}
	if(Channel==3){
		Timer->CCMR2 &= ~TIM_CCMR2_OC3M;          // Effacer les bits du mode de comparaison
		Timer->CCMR2 |= (0x6 << 4);  // R gler le mode PWM 1 (0x6)
		Timer->CCMR2 |= TIM_CCMR2_OC3PE;          // Activer le pr chargement pour la comparaison
		Timer->CCER |= TIM_CCER_CC3E;             // Activer la capture/comparaison pour le canal 1 (activer le canal 1 )
	}
	if(Channel==4){
		Timer->CCMR2 &= ~TIM_CCMR2_OC4M;          // Effacer les bits du mode de comparaison
		Timer->CCMR2 |= (0x6 << 12);  // R gler le mode PWM 1 (0x6)
		Timer->CCMR2 |= TIM_CCMR2_OC4PE;          // Activer le pr chargement pour la comparaison
		Timer->CCER |= TIM_CCER_CC4E;             // Activer la capture/comparaison pour le canal 2 (activer le canal 2 )
	}
}
void MyTimer_SetDutyCycle(TIM_TypeDef * Timer, char Channel, double dutycycle) {
	
	double pulse = dutycycle * (Timer->ARR+1)/100;
  
	if(Channel==1){
		Timer->CCR1=pulse;
	}
	if(Channel==2){
		Timer->CCR2=pulse;
	}
	if(Channel==3){
		Timer->CCR3=pulse;
	}
	if(Channel==4){
		Timer->CCR4=pulse;
	}
}