#include "stdafx.h"
#include "Persoana.h"

#pragma warning(disable : 4996)
Persoana::Persoana()
{ 
	this->nume = NULL;
	this->varsta = 0;
}

Persoana::Persoana(char *& nume, const int & varsta)
{
	if (nume != NULL)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	else this->nume = NULL;
	this->varsta = varsta;
}


Persoana::~Persoana()
{
	if (this->nume != NULL)
		delete this->nume;
	this->nume = NULL;
}
