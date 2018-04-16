#pragma once
#include "Piesa.h"

class Piesa_A :
	public Piesa
{
public:
	int gauri;

	Piesa_A();
	Piesa_A(char * cod, int pret, int gauri);
	Piesa_A(const Piesa_A &);
	Piesa_A& operator=(const Piesa_A &);
	virtual void afisare();
	virtual ~Piesa_A();
};

