#include "stdafx.h"
#include "Piesa.h"

#pragma warning(disable : 4996)
Piesa::Piesa()
{
	this->pret = 0;
}

Piesa::Piesa(char * cod, int pret)
{
	if (cod != NULL) {
		if (strlen(cod) <= 3)
			strcpy(this->cod, cod);
	}
	this->pret = pret;
}

Piesa::Piesa(const Piesa & tmp)
{
	*this = tmp;
}

Piesa & Piesa::operator=(const Piesa & tmp)
{
	if (this != &tmp)
	{
		if (tmp.cod != NULL) {
			if (strlen(tmp.cod) <= 3)
				strcpy(this->cod, tmp.cod);
		}
		this->pret = tmp.pret;
	}
	return *this;
}

int Piesa::getPret()
{
	return this->pret;
}

void Piesa::afisare()
{
	cout << "@ Cod: " << this->cod << " | Pret: " << this->pret << '\n';
}

Piesa::~Piesa()
{
}

