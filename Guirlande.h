#ifndef DEF_GUIRLANDE
#define DEF_GUIRLANDE

#include "GestionBouttons.h"

class Guirlande
{
	public :

	Guirlande();
	void guirlande(int);
	void loopOnGuirlande();
	void modGuirlande(Guirlande,GestionBouttons);

	private :

	bool pattern[6];
	int modeGuirlande;
};

#endif
