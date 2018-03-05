#include "ModTools.h"
#include "global.h"
#include "mbed.h"

ModTools::ModTools()
{
	mode=1;
	change=0;
}

/*void ModTools::choixMode(Guirlande gu)
{
	if(buttons[0]||choseOne)
	{
		wait(0.2);
		choseOne=true;
		if(buttons[0]) {mode=1; gu.guirlande(1); change=0; choseOne=false;}
		if(buttons[1]) {mode=1; gu.guirlande(2); change=0; choseOne=false;}
		if(buttons[2]) {mode=1; gu.guirlande(3); change=0; choseOne=false;}
	}
	if(buttons[1])  mode=2;
	if(buttons[2]) 	mode=3;
}

bool ModTools::modeChanged()
{
	if(buttons[1])
			change++;
	//else if(buttons[0]||buttons[2]||buttons[3]) change=0;

	return change>2;
}

int ModTools::getMode()
{
	return mode;
}*/

void ModTools::choixMode(GestionBouttons gb)
{
	/*
	* Nous avons le choix parmis trois mode
	* - Guirlande (mode 1)
	* - Digicode (mode 2)
	* - Déplacement (mode 3)
	* Ici on se contente de verifier quelle mode à été choisis
	*/
	if(gb.getBoutton()==0) 	{mode=1; change=0;}
	if(gb.getBoutton()==1)  {mode=2; change=0;}
	if(gb.getBoutton()==2) 	{mode=3; change=0;}
}

bool ModTools::modeChanged(GestionBouttons gb)
{
	/*
	* Pour changer de mode il faut appuyer trois fois sur le boutton 1
	* Ici on verifie si le boutton 1 à été préssé et si c'est le cas
	* on incrémente le nombre de fois ou il as été pressé
	* Si un autre boutton à été préssé alors on reviens à 0 pressions sur le 
	* boutton 1
	*/
	if(gb.getBoutton()==1)
			change++;
	else if(gb.getBouttonPrec()!=4||gb.getBouttonPrec()!=1)
		change=0;

	return change>2;
}

int ModTools::getMode()
{
	return mode;
}
