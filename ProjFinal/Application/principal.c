#include "stm32f10x.h"

int main ( void )
{
	// APB2ENR est un registre du RCC ( RESET AND CLOCK CONTROL ) qui gere les horloges du micro controleur
	// On fait un ou logique entre 0x01 << 2 ( 000100 ) ET 0x01 << 3 et 0x01 << 4 ainsi que l'adresse du registre APP2ENR  
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ;
	// 								000100        001000         010000
	
//	00010000 0x1 << 4
//|	00001000 0x1 << 3
//|	00000100 0x1 << 2
//=	00011100 = 28 

 	
	//User button -->	PC13 
	//User LD2: the green LED is connected to PA5 (pin 21) or PB13 (pin 34)
	GPIOA->CRL &= ~(0xF) ;										
	GPIOA->CRL |= (0x1) ;

	//configuration bouton poussoir pull down
	GPIOC->CRH &= ~(0xF) ; //Effacer les bits de configuration
	GPIOC->CRH |= (0x4) ;

	
	
	// Pour allumer une led en vert il faut choisir un mode output quelque soit
	// ensuite on choisi le CNF en output push-pull puis on joue avec le bit 5
	// qui correspond a PA.5
	do 
	{
		//lire l'etat du bouton poussoir PC8
		if ((GPIOC->IDR & (1 << 8) )==0) {
            // Si bouton appuyé, allumer la LED (PA0)
            GPIOA->BSRR = (1 << 0);  // Mettre PA0 à HIGH
        } else {
            // Si bouton relâché, éteindre la LED
            GPIOA->BRR = (1 << 0);   // Mettre PA0 à LOW
        }
	} while (1);
	

	
	

}
