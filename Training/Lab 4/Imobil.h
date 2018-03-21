#ifndef IMOBIL_H
#define IMOBIL_H
#include "Adresa.h"

class Imobil {
	private:
		Adresa a;
		char* descriere; // casa 150 mp, apartament 3 cam, etc
		int pret;
		bool de_inchiriat; // true - daca da, altfel de vanzare - false
	public:	
		//sa implementeze (constructor cu param, de copiere, op=, op<<, destr)
		Imobil();
		Imobil(const Adresa& ad, char* descriere, int p, bool d);
		Imobil(const Imobil& i);
		Imobil & operator= (const Imobil& i);
		friend ostream& operator<<(ostream &dev,const Imobil &i);
		~Imobil();
		
		// pt celelalte cerinte
		int pr() const;
		int loc() const;
		char * adr() const;
		bool liber() const;
};

#endif
