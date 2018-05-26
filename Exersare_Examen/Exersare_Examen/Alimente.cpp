#include "stdafx.h"
#include "Alimente.h"


Alimente::Alimente()
{
}

Alimente::Alimente(std::string nume, unsigned int cod, unsigned int pret): Produse(nume, cod, pret)
{
}

Alimente::Alimente(std::string nume, unsigned int cod, unsigned int pret, std::string ingredient, std::string nutrienti) : Produse(nume, cod, pret)
{
	this->ingrediente = ingrediente;
	this->nutrienti = nutrienti;
}

Alimente::Alimente(const Alimente & tmp)
{
	*this = tmp;
}

Alimente & Alimente::operator=(const Alimente & tmp)
{
	if (this != &tmp)
	{
		(Produse)(*this) = (Produse)tmp;
		this->ingrediente = tmp.ingrediente;
		this->nutrienti = tmp.nutrienti;
	}
	return *this;
}


Alimente::~Alimente()
{
}

std::ostream & operator<<(std::ostream os, const Alimente & tmp)
{
	os << "- Nume: " << tmp.nume << " | Cod: " << tmp.cod << " | Pret: " << tmp.pret << '\n';
	os << "- Ingrediente: " << tmp.ingrediente << " | Nutrienti: " << tmp.nutrienti << '\n';
	return os;
}
