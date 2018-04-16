#include <iostream>
#include "Teren.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	// DECLARERE VECTOR
	const int n = 10;
	Propietate** pipera = new Propietate*[n];
	
	// VALORI
	for(int i = 0; i < n; i += 2)
	{
		Imobil tmp("past", 10 * i, "dudu", 400/i);
		*pipera[i] = tmp;
		
		Teren tmp1("rur", 17 * i, "mumu", 580/i, 20*i, 25 * i);
		*pipera[i+1] = tmp1;
	}
	
	  
	/*  
	  
	// SORTARE
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			if(pipera[i]->getVenitPeLuna() > pipera[j]->getVenitPeLuna())
			{
				Propietate* tmp = pipera[i];
				pipera[i] = pipera[j];
				pipera[j] = tmp;
			}
		}
	}
	
	*/
	
	/*
	// AFISARE
	for(int i = 0; i < n; i ++)
	{
		pipera[i]->afisare();
	}
	
	*/
	
	/*
	// CU CEA MAI MICA VALOARE
	int vmin = pipera[0]->getValoare();
	int index = 0;
	
	for(int i = 1; i < n; i ++)
	{
		if(pipera[i]->getValoare() < vmin)
		{
			int vmin = pipera[i]->getValoare();
			int index = i;
		}
	}
	
	pipera[index]->afisare();
	*/ 
	return 0;
}
