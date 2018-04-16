#ifndef ELECTROCASNICE_H
#define ELECTROCASNICE_H

#include "Produs.h"

class Electrocasnice : public Produs
{
	protected:
		char *marca;
	
	public:
		Electrocasnice();
		Electrocasnice(char *, int , char *);
		~Electrocasnice();
		void afisare();
				
};

#endif
