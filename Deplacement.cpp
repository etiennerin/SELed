#include "Deplacement.h"
#include "global.h"

Deplacement::Deplacement()
{
	positionActuelle=0;
}

void Deplacement::deplacement(GestionBouttons gb)
{
	int anciennePosition=this->positionActuelle;

	//eteint toutes les leds
	for(int i = 0; i<pixels;i++)
		myleds[i]=0;

	/*
	* Si le boutton (0) est pressé, alors on passe à la led suivante 
	* (à droite de la led actuelle)
	*/
	if(gb.getBoutton()==0)
		this->positionActuelle-=2;

	/*
	* Si le boutton (1) est pressé, alors on passe à la led suivante 
	* (en haut de la led actuelle)
	*/
	if(gb.getBoutton()==1)
		if(!(this->positionActuelle%2))
			this->positionActuelle++;

	/*
	* Si le boutton (2) est pressé, alors on passe à la led suivante 
	* (en bas de la led actuelle)
	*/
	if(gb.getBoutton()==2)
		if((this->positionActuelle%2))
			this->positionActuelle--;

	/*
	* Si le boutton (2) est pressé, alors on passe à la led suivante 
	* (à gauche de la led actuelle)
	*/
	if(gb.getBoutton()==3)
		this->positionActuelle+=2;

	/*
	* si la position actuelle dépasse les 6 leds(passe à une n eme led
	* alors on ne fais rien(ne change pas la position)
	*/
	if((this->positionActuelle<0)||(this->positionActuelle>=pixels))
		this->positionActuelle=anciennePosition;

	/*
	* On allume la led concernée par un des changements ci-dessus	
	*/
	this->positionActuelle=this->positionActuelle%pixels;
	myleds[this->positionActuelle]=1;
}
