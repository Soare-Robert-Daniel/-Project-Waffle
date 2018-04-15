#pragma once
#include "Piesa.h"
class Piesa_B :
	public Piesa
{
public:
	char * culoare;

	Piesa_B();
	Piesa_B(char * cod, int pret, char * culoare);
	Piesa_B(const Piesa_B &);
	Piesa_B& operator=(const Piesa_B &);
	void afisare();
	virtual ~Piesa_B();
};

