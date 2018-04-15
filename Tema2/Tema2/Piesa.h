#include "Object.h"
#pragma once
class Piesa :
	public Object
{
protected:
	char cod[4];
	int pret;
public:
	Piesa();
	Piesa(char * cod, int pret);
	Piesa(const Piesa &);
	Piesa& operator=(const Piesa &);
	int getPret();
	virtual void afisare();
	virtual ~Piesa();
};

