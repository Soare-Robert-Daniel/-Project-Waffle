#ifndef PROPIETATE_H
#define PROPIETATE_H
#include <iostream>
#include <string.h>
#include "Interfata.h"
using namespace std;

class Propietate
{
	protected:
		char * adresa;
		double valoare;
		
	public:
		Propietate(){};
		Propietate(char*, double);
		virtual ~Propietate();
		virtual void afisare(){ cout << "Adresa: " << adresa << " | Valoare: " << valoare << '\n';}
		virtual float getValoare(){ return valoare;}
		virtual double getVenitPeLuna();
		Propietate operator=(const Propietate);
};

#endif
