#ifndef TEREN_H
#define TEREN_H

#include "Imobil.h"

class Teren : public Imobil
{
	protected:
		double suprafata;
		double pret;
	public:
		Teren();
		Teren(char*, double, char*, double, double , double);
		~Teren();
		
		void afisare(){
			Imobil::afisare();
			cout << "Suprafata: " << suprafata << " | Pret: " << pret << '\n';
		}
		
		Teren operator= (const Teren);
};

#endif
