#include "Imobil.h"

Imobil::Imobil(char* ad, double val, char* info, double venit_an): Propietate(ad, val)
{
	if(info != NULL)
	{
		this->info = new char[strlen(info)+1];
		strcpy(this->info, info);
	} else this->info = NULL;
	this->venit_an = venit_an;
}

Imobil::~Imobil()
{
	if(info != NULL)
	{
		delete this->info;	
	} 
	this->info = NULL;
}

Imobil Imobil::operator=(const Imobil tmp)
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
	}
	return *this;
}
