#pragma once
class Persoana
{
protected:
	char * nume;
	int varsta;
public:
	Persoana();
	Persoana(char * &, const int &);
	virtual ~Persoana();
};

