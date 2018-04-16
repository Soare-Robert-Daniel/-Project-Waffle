#ifndef IMOBIL_H
#define IMOBIL_H

#include "Propietate.h"

class Imobil : public Propietate
{
	protected:
		double venit_an;
		char* info;
	public:
		Imobil(){}
		Imobil(char*, double, char*, double);
		virtual ~Imobil();
		
		virtual void afisare(){Propietate::afisare(); cout << "Info: " << info << " | Venit pe an: " << venit_an << '\n';}
		virtual double getVenitPeLuna(){return venit_an/12;}
		
		Imobil operator=(const Imobil);
};

#endif
