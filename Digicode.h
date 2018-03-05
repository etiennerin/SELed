#ifndef DEF_DIGICODE
#define DEF_DIGICODE

#include "GestionBouttons.h"

class Digicode
{
	public :

		Digicode();
		int digicode(GestionBouttons);

	private :

		int digicodePattern[4];
		int rightCode;

};

#endif
