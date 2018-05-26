#include "stdafx.h"
#include "Electronice.h"


Electronice::Electronice()
{
}

Electronice::Electronice(std::string nume, unsigned int cod, unsigned int pret): Produse(nume,cod,pret)
{

}

Electronice::Electronice(std::string nume, unsigned int cod, unsigned int pret, std::string detalii_tehnice) : Produse(nume, cod, pret)
{
	this->detalii_tehnice = detalii_tehnice;
}

Electronice::Electronice(const Electronice & tmp)
{
	*this = tmp;
}

Electronice & Electronice::operator=(const Electronice & tmp)
{
	if (this != &tmp)
	{
		(Produse)(*this) = (Produse)tmp;
		this->detalii_tehnice = tmp.detalii_tehnice;
	}
	return *this;
}


Electronice::~Electronice()
{
}

std::ostream & operator<<(std::ostream & os, const Electronice & tmp)
{
	os << "- Nume: " << tmp.nume << " | Cod: " << tmp.cod << " | Pret: " << tmp.pret << '\n';
	os << "- Detalii Tehnice: " << tmp.detalii_tehnice << '\n';
	return os;
}
