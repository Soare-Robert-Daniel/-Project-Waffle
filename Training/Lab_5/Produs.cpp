#include "Produs.h"

Produs::Produs(char *c, int p): pret(p)
{
	strcpy(cod, c);
}

Produs::Produs()
{
	
}

void Produs::afisare()
{
	cout << "# Cod: " << cod << " | Pret: " << pret << " $ ";
}
