#include "PlateauService.h"
#include "ServiceGirouette.h"
#include "VoileService.h"
#include <stdio.h>

int var;
int main() {
 //   initPlateau();
	initServoMoteur();
	var=10;

    while (1) {
        // Wait for data reception via interrupt
		//	controlVitesse(var);
		setPosServoMoteur(var);
		
		//wait 1 sec 
			
			//controlVitesse(60);
					//wait 1 sec 
			
    }
}