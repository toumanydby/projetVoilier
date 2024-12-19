#include "stm32f10x.h"
#include "codeur_inc.h"
#include "constantes.h"


void Encoder_Init(TIM_TypeDef * Timer){
	if(Timer == TIM1) {RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;}
	else if(Timer == TIM2) {RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;}
	else if(Timer == TIM3) {RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;}
	else if(Timer == TIM4) {RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;}

     Timer->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;

		Timer->CCMR1 |= TIM_CCMR1_CC1S_0;
		Timer->CCMR1 |= TIM_CCMR1_CC2S_0;
		 
		Timer->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);
		
		Timer->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E;
		 
		Timer->ARR = 1440-1;

		Timer->PSC = 0;
	 
		Timer->CR1 |= TIM_CR1_CEN;

		MyGPIO_Init(GPIO_IC1_CodIncr, GPIOPin_IC1_CodIncr,In_Floatting );
		MyGPIO_Init(GPIO_IC2_CodIncr, GPIOPin_IC2_CodIncr,In_Floatting );
}

void Z_Pin_Interrupt_Init(void) {
    // Assuming Z is connected to pin PA0 (EXTI line 0)

    // 1. Enable the clock for GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // 2. Configure PA0 as input
    GPIOA->CRL &= ~GPIO_CRL_MODE0;  // Input mode
    GPIOA->CRL &= ~GPIO_CRL_CNF0;  // Floating input

    // 3. Enable EXTI0 interrupt
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;  // Enable AFIO clock
    AFIO->EXTICR[0] &= ~AFIO_EXTICR1_EXTI0;  // Map EXTI0 to PA0

    EXTI->IMR |= EXTI_IMR_MR0;  // Unmask EXTI line 0
    EXTI->RTSR |= EXTI_RTSR_TR0;  // Trigger on rising edge

    // 4. Enable the interrupt in the NVIC
    NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(TIM_TypeDef * Timer) {
    if (EXTI->PR & EXTI_PR_PR0) {  // Check if EXTI line 0 triggered
        Timer->CNT = 0;  // Reset the counter

        EXTI->PR |= EXTI_PR_PR0;  // Clear the pending bit
    }

}
uint32_t read_encoder_value(TIM_TypeDef * Timer){
	return Timer -> CNT;
}