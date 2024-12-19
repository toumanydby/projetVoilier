#include "stm32f10x.h"
#include "Communication.h"
#include "PlateauService.h"
#include "VoileService.h"

int received_vitesse;
char received_sens;
int pos;

int main(void) {
	initPlateau();
	Communication_Conf();
	initServoMoteur();
	initGirouette();
	
	pos=60;

	while (1) {			
		received_vitesse= read_vitesse();
		received_sens = read_sens();
		controlVitesse(received_vitesse);
		controlSens(received_sens);
		
		controle_voile();
		
	}
}