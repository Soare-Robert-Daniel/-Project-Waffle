#include "Propietate.h"

Propietate::Propietate(char* adresa, double valoare)
{
	if(adresa != NULL)
	{
		this->adresa = new char[strlen(adresa)+1];
		strcpy(this->adresa, adresa);
	} else this->adresa = NULL;
	this->valoare = valoare;
}

Propietate::~Propietate()
{
	if(adresa != NULL)
	{
		delete this->adresa;	
	} 
	this->adresa = NULL;
}
