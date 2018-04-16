#pragma once
#include "Object.h"
#include "Piesa_A.h"
#include "Piesa_B.h"
class Ansamblu :
	public Object
{
public:
	Piesa_A pa;
	Piesa_B *vec;

	Ansamblu();
	Ansamblu(Piesa_A &, Piesa_B * &);
	Ansamblu(const Ansamblu &);
	Ansamblu& operator=(const Ansamblu &);
	virtual void afisare();
	virtual int getPret();
	virtual ~Ansamblu();
};

