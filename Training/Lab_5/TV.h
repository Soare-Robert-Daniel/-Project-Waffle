#ifndef TV_H
#define TV_H

#include "Electrocasnice.h"

class TV : public Electrocasnice
{
	protected:
		int diagonala;
		char * info_sup;
	public:
		TV();
		TV(char *, int , char *, int d, char *);
		TV(const TV&);
		~TV();	
		
		void afisare();
		
		TV & operator= (const TV &tmp);
		char * GetMarca();
		char * GetCod();
		char * GetInfo();
		int GetPret();
		int GetDiag();	
};

#endif
