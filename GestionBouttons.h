#ifndef DEF_GESTIONBOUTTONS
#define DEF_GESTIONBOUTTONS

class GestionBouttons
{
	public :

		GestionBouttons();
		int pressionBoutton();
		int getBoutton();
		int getBouttonPrec();
		bool getPression();

	private :

		int bouttonPresse;
		int bouttonPrec;
		bool pression;

};

#endif
