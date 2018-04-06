#include "stdafx.h"
#include "Album.h"

#pragma warning(disable : 4996)
Album::Album()
{
	this->an = 0;
	this->nume = NULL;
}

Album::Album(char *& nume, const int & an)
{
	if (nume != NULL)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	else this->nume = NULL;
	this->an = an;
}

Album::Album(char *& nume, const int & an,  vector<Track> & lista)
{
	if (nume != NULL)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	else this->nume = NULL;
	this->an = an;
	this->lista = lista;
}

Album::Album(const Album & tmp)
{
	nume = NULL;
	*this = tmp;
}

void Album::Modifica(char *& nume, const int & an)
{
	if (nume != NULL)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}
	else this->nume = NULL;
	this->an = an;
}

void Album::SetLista(const vector<Track> & lista)
{
	this->lista = lista;
}

void Album::AdaugaTrack( const Track & tmp)
{
	lista.push_back(tmp);
	lista[lista.size() - 1].modifica(lista.size() - 1);
}

void Album::AdaugaTrack( char *& nume, const int & pozitie)
{
	Track tmp(nume, pozitie);
	this->lista.push_back(tmp);
}

void Album::ModificaTrack(const int & index, const Track & tmp)
{
	this->lista[index] = tmp;
}

void Album::ModificaTrack(const int & index,  char *& nume)
{
	Track tmp(nume, index);
	this->lista[index] = tmp;
}

void Album::StergeTrack(const int & index)
{
	// [!] indexarea se face de la 0
	this->lista.erase(this->lista.begin() + index);

	// actualizam celelalte pozitii din album
	for (unsigned int i = 0; i < this->lista.size(); ++i)
		this->lista[i].modifica(i);
}

Album & Album::operator=(const Album & tmp)
{
	if (this != &tmp)
	{
		if (tmp.nume != NULL)
		{
			this->nume = new char[strlen(tmp.nume) + 1];
			strcpy(this->nume, tmp.nume);
		}
		else this->nume = NULL;
		this->an = tmp.an;
		this->lista = tmp.lista;
	}
	return *this;
}

Album::~Album()
{
	if (this->nume != NULL)
		delete this->nume;
	this->nume = NULL;
}

ostream & operator<<(ostream & os, const Album & tmp)
{
	os << tmp.an << " - " << tmp.nume;
	return os;
}

bool operator<(const Album & a, const Album & b)
{
	return a.an < b.an;
}

bool operator<=(const Album & a, const Album & b)
{
	return a.an <= b.an;
}

bool operator>(const Album & a, const Album & b)
{
	return a.an > b.an;
}

bool operator>=(const Album & a, const Album & b)
{
	return a.an >= b.an;
}
