#include "stm32f10x.h"
#include "PlateauService.c"
#include "ServiceGirouette.h"
#include "VoileService.h"
#include "CommunicationService.h"

int main ( void )
{
	// on init la communication avec le module x-bee pour les instructions du plateau 
	init_Communication_UART();
				
				// on initialise le plateau et on le lance
				initPlateau();
				startPlateau();
						
							// on initialise le servo moteur des voiles et le codeur incremental pour la girouette
							initServoMoteur();
							initGirouette();
	
	// quand la psotion du plateau change, on recup la nouvelle valeur affecte la nouvelle position du 
	// plateau grace a data et ensuite on controle la voile, on place le bon angle pour les voiles en
	// fonction du nouvel angle de girouette.
	while (1)
	{
		data();
					controle_voile();
	}
}
