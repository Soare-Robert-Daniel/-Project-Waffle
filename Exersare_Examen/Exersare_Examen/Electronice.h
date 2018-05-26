#pragma once
#include "Produse.h"
class Electronice :
	public Produse
{
private:
	std::string detalii_tehnice;
public:
	Electronice();
	Electronice(std::string, unsigned int, unsigned int);
	Electronice(std::string, unsigned int, unsigned int, std::string);
	Electronice(const Electronice&);
	Electronice & operator=(const Electronice&);
	friend std::ostream & operator<<(std::ostream & os, const Electronice&);
	virtual ~Electronice();
};

