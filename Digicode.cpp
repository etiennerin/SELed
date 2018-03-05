#include "Digicode.h"
#include "global.h"

Digicode::Digicode()
{
	rightCode=0;
	int dgcp[4]={3,1,0,2};
	/*
	* On initialise le pattern du digicode avec la valeur ci-dessus
	* (juste une création de variable en sorte)
	*/
	for(int i = 0;i<(sizeof(this->digicodePattern)/sizeof(*this->digicodePattern));i++)
		this->digicodePattern[i]=dgcp[i];
}

int Digicode::digicode(GestionBouttons gb)
{
	bool bonCode=0;
	int rightCodePrec=rightCode;

	/*
	* On parcours la liste des bouttons et verifie si le boutton qui as été 	* préssé est le bon boutton 
	* (Un des bouttons du pattern)
	* Si la pression de ce boutton suit la pression du bouton précédent dans 	 * le pattern alors on incrémente la variable determinant si le bon code 	* à été tape en entier
	*/
	for(int i = 0; i<(sizeof(buttons)/sizeof(*buttons));i++)
			if	(((gb.getBouttonPrec()==4)||
				(gb.getBouttonPrec()==digicodePattern[i-1]))&&
				(gb.getBoutton()==digicodePattern[i]))
					rightCode++;

	// Si un boutton différent à été tapé alors on reppart de zero
	if((gb.getBoutton()!=4)&&(rightCode==rightCodePrec))
		rightCode=0;

	/*for(int i = 0; i<(sizeof(buttons)/sizeof(*buttons));i++)
		if(buttons[i])
			if(i==digicodePattern[i])
				rightCode++;*/

	/*if(buttons[0])
	if(buttons[1])
	if(buttons[2])
	if(buttons[3])*/

	// En revanche si le bon code à été tapé on notifie du bon déroulement
	if(rightCode==3)
		bonCode=1;

	return bonCode;
}
