#include "stdafx.h"
#include "Piesa_A.h"

#pragma warning(disable : 4996)
Piesa_A::Piesa_A()
{
	this->gauri = 0;
}

Piesa_A::Piesa_A(char * cod, int pret, int gauri) : Piesa(cod, pret)
{
	this->gauri = gauri;
}

Piesa_A::Piesa_A(const Piesa_A & tmp)
{
	*this = tmp;
}


Piesa_A & Piesa_A::operator=(const Piesa_A & tmp)
{
	if (this != &tmp)
	{
		if (tmp.cod != NULL) {
			if (strlen(tmp.cod) <= 3)
				strcpy(this->cod, tmp.cod);
		}
		this->pret = tmp.pret;
		this->gauri = tmp.gauri;
	}
	return *this;
}

void Piesa_A::afisare()
{
	Piesa::afisare();
	cout << "# Numar de gauri " << this->gauri << '\n';
}

Piesa_A::~Piesa_A()
{
}
