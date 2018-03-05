#include "GestionBouttons.h"
#include "global.h"

GestionBouttons::GestionBouttons()
{
	bouttonPrec=4;
	bouttonPresse=4;
	pression=false;
}

int GestionBouttons::pressionBoutton()
{
	/*
	* Si un bouton à été pressé lors de l'appel précédent de la méthode
	* alors on enregistre celui ci en tant que boutton pressé précédement
	*/
	if((bouttonPresse!=4)&&(bouttonPrec!=bouttonPresse))
			bouttonPrec=bouttonPresse;

	// On réinitialise le boutton et le test de pression
	bouttonPresse=4;
	pression=false;

	/*
	* si un boutton à été pressé alors on l'enregistre en tant que boutton 	 	 * pressé
	*/
	if(buttons[0]){
		pression=true;
		bouttonPresse=0;
	}
	if(buttons[1]){
		pression=true;
		bouttonPresse=1;
	}
	if(buttons[2]){
		pression=true;
		bouttonPresse=2;
	}
	if(buttons[3]){
		pression=true;
		bouttonPresse=3;
	}
}

int GestionBouttons::getBouttonPrec()
{
	return bouttonPrec;
}

int GestionBouttons::getBoutton()
{
	return bouttonPresse;
}

bool GestionBouttons::getPression()
{
	return pression;
}
