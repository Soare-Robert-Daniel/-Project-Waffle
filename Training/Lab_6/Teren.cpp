#include "Teren.h"

Teren::Teren(char* ad, double val, char* inf, double venit, double suprafata, double pret): Imobil(ad, val, inf, venit)
{
	this->suprafata = suprafata;
	this->pret = pret;
}

Teren::~Teren()
{
}

Teren Teren::operator= (const Teren tmp) 
{
	if(this != &tmp)
	{
		if(tmp.adresa != NULL)
		{
			this->adresa = new char[strlen(tmp.adresa)+1];
			strcpy(this->adresa, tmp.adresa);
		} else this->adresa = NULL;
		this->valoare = tmp.valoare;
		if(tmp.info != NULL)
		{
			this->info = new char[strlen(tmp.info)+1];
			strcpy(this->info, tmp.info);
		} else this->info = NULL;
		this->venit_an = tmp.venit_an;
		this->suprafata = tmp.suprafata;
		this->pret = tmp.pret;
	}
	return *this;
}
