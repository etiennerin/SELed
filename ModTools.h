#ifndef DEF_MODTOOLS
#define DEF_MODTOOLS

#include "GestionBouttons.h"

class ModTools
{
	public:

		ModTools();
		bool modeChanged(GestionBouttons);
		void choixMode(GestionBouttons);
		int getMode();

	private:

		int mode;
		int change;
};

#endif
