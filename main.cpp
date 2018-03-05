#include "mbed.h"
#include "global.h"
#include "Guirlande.h"
#include "Deplacement.h"
#include "Digicode.h"
#include "ModTools.h"
#include "GestionBouttons.h"

//Initialisation des leds et bouttons (sous forme de tableaux)
DigitalOut myleds[6]={(P0_9),(P0_10),(P0_7),(P0_8),(P0_5),(P0_6)};
DigitalOut buttons[4]={(P0_19),(P0_20),(P0_17),(P0_18)};

int main() {
	// Création des objets utilisés
	Guirlande gu;
	Deplacement dep;
	Digicode dc;
	ModTools mt;
	GestionBouttons gb;

// BOucle du programme
    while(1) {
	// On verifie si un boutton à été pressé
    	gb.pressionBoutton();
	// si c'est le cas on passe à la sélection de mode
    	if(mt.modeChanged(gb))
    		mt.choixMode(gb);
	/*
	* si le mode guirlande à été sélectionné et qu'aucun mode de guirlande
	* n'est encore choisis alors on offre à l'utilisateur la possibilité
	* d'en choisir un
	* par défaut ce sera le mode 1 qui s'executera (gu.loopOnGuirlande)
	*/
    	if(mt.getMode()==1)
    	{
    		if	((gb.getBouttonPrec()!=4)&&
				((gb.getBoutton()!=gb.getBouttonPrec())||
				((gb.getBoutton()==gb.getBouttonPrec())&&(gb.getPression()))))
    			gu.modGuirlande(gu,gb);
    		gu.loopOnGuirlande();
    	}
	/*
	* si le mode a changé pour 2 alors on vas appeler la mathode digicode 
	* de la classe digicode
	*/
    	if(mt.getMode()==2) myleds[0]=dc.digicode(gb);
	// Si le mode 3 est enclanché alors on execute le mode déplacement
    	if(mt.getMode()==3) dep.deplacement(gb);
    	wait(0.2);
    }
}
