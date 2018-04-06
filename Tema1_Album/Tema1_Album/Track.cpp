#include "stdafx.h"
#include "Track.h"

#pragma warning(disable : 4996)
Track::Track()
{
	nume = NULL;
	pozitie = -1;
}

Track::Track(char *&)
{
	if (nume != NULL)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	else this->nume = NULL;
}

Track::Track(char * &nume,const int &pozitie)
{
	if (nume != NULL)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	else this->nume = NULL;
	this->pozitie = pozitie;
}

Track::Track(const Track & tmp)
{
	this->nume = NULL;
	*this = tmp;
}

Track& Track::operator=(const Track & tmp)
{
	if (this != &tmp)
	{
		if (tmp.nume != NULL)
		{
			this->nume = new char[strlen(tmp.nume) + 1];
			strcpy(this->nume, tmp.nume);
		}
		else this->nume = NULL;
		this->pozitie = tmp.pozitie;
	}
	return *this;
}

void Track::modifica(const int & pozitie)
{
	this->pozitie = pozitie;
}

void Track::modifica(char * nume)
{
	if (nume != NULL)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	else this->nume = NULL;
}

void Track::modifica(const int & varsta,  char * nume)
{
	if (nume != NULL)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	else this->nume = NULL;
	this->pozitie = pozitie;
}

ostream& operator<<(ostream& os, const Track& tmp)
{
	if(tmp.nume != NULL)
		os << tmp.nume;
	else os << "Eroare de citire!";
	return os;
}

Track::~Track()
{
	if (this->nume != NULL)
		delete this->nume;
	this->nume = NULL;
}
