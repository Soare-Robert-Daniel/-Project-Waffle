#include "Electrocasnice.h"

Electrocasnice::Electrocasnice(char *c, int p,char *m):Produs(c, p)
{
	marca = new char[strlen(m)];
	strcpy(marca, m);
}

Electrocasnice::Electrocasnice()
{
	
}

void Electrocasnice::afisare()
{
	Produs::	afisare();
	cout << "| Marca: " << marca << " ";
}

Electrocasnice::~Electrocasnice()
{
	delete marca;
}

