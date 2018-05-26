#pragma once
class Produse
{
protected:
	std::string nume;
	unsigned int cod;
	unsigned int pret;

public:
	Produse();
	Produse(std::string, unsigned int, unsigned int);
	Produse(const Produse&);
	Produse & operator=(const Produse&);
	friend std::ostream & operator<<(std::ostream & os, const Produse&);
	virtual ~Produse();
};

