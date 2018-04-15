#include "stdafx.h"
#include "Piesa_B.h"

#pragma warning(disable : 4996)
Piesa_B::Piesa_B()
{
}

Piesa_B::Piesa_B(char * cod, int pret, char * culoare) : Piesa(cod, pret)
{
	if (culoare != NULL) {
		this->culoare = new char[strlen(culoare) + 1];
		strcpy(this->culoare, culoare);
	}
}

Piesa_B::Piesa_B(const Piesa_B & tmp )
{
	this->culoare = NULL;
	*this = tmp;
}

Piesa_B & Piesa_B::operator=(const Piesa_B & tmp)
{
	if (this != &tmp)
	{
		if (tmp.cod != NULL) {
			if (strlen(tmp.cod) <= 3)
				strcpy(this->cod, tmp.cod);
		}
		this->pret = tmp.pret;
		if (tmp.culoare != NULL) {
			this->culoare = new char[strlen(tmp.culoare) + 1];
			strcpy(this->culoare, tmp.culoare);
		}
	}
	return *this;
}

void Piesa_B::afisare()
{
	Piesa::afisare();
	cout << "# Culoare " << this->culoare << '\n';
}


Piesa_B::~Piesa_B()
{
	if (this->culoare != NULL) {
		delete culoare;
	}
	this->culoare = NULL;
}
