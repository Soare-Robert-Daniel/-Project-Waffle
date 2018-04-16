#ifndef PRODUS_H
#define PRODUS_H
#include <iostream>
#include <string.h>
using namespace std;
class Produs
{
	protected:
		char cod[7];
		int pret;
	public:
		Produs();
		Produs(char *, int );
		void afisare();

};

#endif
