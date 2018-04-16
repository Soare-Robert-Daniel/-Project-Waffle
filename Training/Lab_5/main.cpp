#include <iostream>
#include "TV.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool verifica(TV &tmp)
{
	
	if(strcmp(tmp.GetMarca(), "LG") != 0)
		return false;
	
	if(tmp.GetPret() <= 1000)
		return false;	
		
	return true;
}

int main(int argc, char** argv) {

	const int n = 10;
	TV * v = new TV[n];
	
	// POPULEZ CU VALORI
	for(int i = 0; i < n/2; ++i)
	{
		TV tmp("123456", 1000 * i, "LG", 2*i, "Nu exista!");
		v[i] = tmp;
	
	}
	
	for(int i = n/2; i < n; ++i)
	{
		TV tmp("AG2134", 300 * i , "Samsung",i, "Atentie la baterie!");
		v[i] = tmp;
	}
	
	// SORTARE in fuctie de diagonala
	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			if(v[i].GetDiag() > v[j].GetDiag())
			{
				TV tmp(v[i]);
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	
	
	// AFISARE
	for(int i = 0; i < n; ++i)
	{
		if(verifica(v[i]))
			v[i].afisare();
	}
	
	
	return 0;
}
