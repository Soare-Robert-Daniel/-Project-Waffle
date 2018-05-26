#include "stdafx.h"
#include "Produse.h"


Produse::Produse()
{
}

Produse::Produse(std::string name, unsigned int cod, unsigned int pret)
{
	this->nume = nume;
	this->cod = cod;
	this->pret = pret;
}

Produse::Produse(const Produse & tmp)
{
	*this = tmp;
}

Produse & Produse::operator=(const Produse & tmp)
{
	if (this != &tmp)
	{
		this->nume = tmp.nume;
		this->cod = tmp.cod;
		this->pret = tmp.pret;
	}
	return *this;
}


Produse::~Produse()
{
}

std::ostream & operator<<(std::ostream & os, const Produse & tmp)
{
	os << "- Nume: " << tmp.nume << " | Cod: " << tmp.cod << " | Pret: " << tmp.pret << '\n';
	return os;
}
