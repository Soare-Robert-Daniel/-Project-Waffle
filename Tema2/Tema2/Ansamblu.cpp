#include "stdafx.h"
#include "Ansamblu.h"


Ansamblu::Ansamblu()
{
}

Ansamblu::Ansamblu(Piesa_A & pa, Piesa_B *& vec)
{
	this->pa = pa;
	this->vec = new Piesa_B[this->pa.gauri];
	for (int i = 0; i < this->pa.gauri; ++i)
	{
		this->vec[i] = vec[i];
	}
}

Ansamblu::Ansamblu(const Ansamblu & tmp)
{
	this->vec = NULL;
	*this = tmp;
}

Ansamblu & Ansamblu::operator=(const Ansamblu & tmp)
{
	if (this != &tmp)
	{
		this->pa = tmp.pa;
		this->vec = new Piesa_B[this->pa.gauri];
		for (int i = 0; i < this->pa.gauri; ++i)
		{
			this->vec[i] = tmp.vec[i];
		}
	}
	return *this;
}

void Ansamblu::afisare()
{
	cout << "[$] Ansamblu:\n";
	this->pa.afisare();
	for (int i = 0; i < this->pa.gauri; ++i)
	{
		this->vec[i].afisare();
	}
}


int Ansamblu::getPret()
{
	int suma = this->pa.getPret();
	for (int i = 0; i < this->pa.gauri; ++i)
	{
		suma += this->vec[i].getPret();
	}
	return suma;
}

Ansamblu::~Ansamblu()
{
	if (this->vec != NULL) {
		delete[] this->vec;
	}
	this->vec = NULL;
}
