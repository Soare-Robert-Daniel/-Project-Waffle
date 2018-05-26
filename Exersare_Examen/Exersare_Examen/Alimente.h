#pragma once
#include "Produse.h"
class Alimente :
	public Produse
{
protected:
	std::string ingrediente;
	std::string nutrienti;
public:
	Alimente();
	Alimente(std::string, unsigned int, unsigned int);
	Alimente(std::string, unsigned int, unsigned int, std::string, std::string);
	Alimente(const Alimente&);
	Alimente & operator=(const Alimente&);
	friend std::ostream & operator<<(std::ostream os, const Alimente&);
	virtual ~Alimente();
};

