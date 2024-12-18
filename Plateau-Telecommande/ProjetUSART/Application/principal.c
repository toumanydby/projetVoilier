#include "stm32f10x.h"
#include "GPIO.h"
#include "Timer.h"
#include "USART.h"
#include "Communication.h"
#include "PlateauService.h"


//void Callback(void){
//	MyGPIO_Toggle(GPIOC,13);
//}

int received_vitesse;
char received_sens;

int main(void) {
	initPlateau();
	Communication_Conf();
	
	
	
	// Configurar el USART1 a 9600 baudios
	/*USART_Init(USART1, 9600);
	USART1->SR |= USART_SR_RXNE;
	USART1->DR = 'A';
	char c = USART_ReceiveChar(USART1);
	if (c == 'A') {
		// Si el carácter recibido es correcto, envía un mensaje de éxito
		USART_SendChar(USART1, 'S'); // 'S' para "Success"
	} else {
		// Si falla, envía un mensaje de error
		USART_SendChar(USART1, 'E'); // 'E' para "Error"
  }
	while (1); 
}*/


    /*USART_SendChar(USART1, '\n');
    USART_SendChar(USART1, 'I');
    USART_SendChar(USART1, 'n');
    USART_SendChar(USART1, 'i');
    USART_SendChar(USART1, 'c');
    USART_SendChar(USART1, 'i');
    USART_SendChar(USART1, 'o');
    USART_SendChar(USART1, '\n');*/


// Recibir y eco de datos
    
    while (1) {
			
			
			received_vitesse= read_vitesse();
			received_sens = read_sens();
			controlVitesse(received_vitesse);
			controlSens(received_sens);
			
				//char c;
        //c = USART_ReceiveChar(USART1);
        //USART_SendChar(USART1, c);
    }
	}