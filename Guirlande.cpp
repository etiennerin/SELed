#include "Guirlande.h"
#include "global.h"

using namespace std;

Guirlande::Guirlande()
{
	bool t =true;
	// On crée un pattern pour la guirlande(un tableau de led)
	for(int i = 0;i<sizeof(this->pattern)/sizeof(*this->pattern);i++)
	{
		this->pattern[i]=t;
		t=!t;
	}
}

void Guirlande::guirlande(int programme)
{
	bool t =true;
	bool j = false;

	/* 
	* On choisis le pattern sélectionné selon le bouton pressé lors de la
	* séléction du mode de la guirlande
	* Nous avons un tableau différent pour chaque case
	*/
	switch(programme)
	{
		case 1:
			for(int i = 0;i<sizeof(this->pattern)/sizeof(*this->pattern);i++)
			{
				this->pattern[i]=t;
				t=!t;
			}
			break;
		case 2:
			for(int i = 0;i<sizeof(this->pattern)/sizeof(*this->pattern);i++)
			{
				if(i%2==0)
					j=true;
				else
					j=false;
				if(j) this->pattern[i]=true;
				else this->pattern[i]=false;
			}
			break;
		case 3:
			for(int i = 0;i<3;i++)
				this->pattern[i]=true;
			for(int i = 2;i<6;i++)
				this->pattern[i]=false;
			break;
	}
}

void Guirlande::loopOnGuirlande()
{
	//On alterne les leds allumées et etteintes
	for(int i = 0; i<pixels;i++)
		if(this->pattern[i])
		{
			myleds[i]=1;
			this->pattern[i]=!this->pattern[i];
		}
		else
		{
			myleds[i]=0;
			this->pattern[i]=!this->pattern[i];
		}
}

void Guirlande::modGuirlande(Guirlande gu, GestionBouttons gb)
{
	/* 
	* Selection du mode de la guirlande(indiqué dans la méthode guirlande)
	* On verifie  quelle boutton à été pressé lors de la sélection du mode 
	* pour savoir quelle mode à été choisis
	*/
	if(gb.getBoutton()==0) gu.guirlande(1);
	if(gb.getBoutton()==1) gu.guirlande(2);
	if(gb.getBoutton()==2) gu.guirlande(3);
}

