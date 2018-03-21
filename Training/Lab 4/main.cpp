#include <iostream>
#include "Adresa.h"
#include "Imobil.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
1 .In main sa creeze obiecte de tip Firma/Imobil. Sa explice ce metode din Adresa se
folosesc in clasa agregata si unde.
2. Sa creeze un vector pt evidenta imobilelor respectiv firmelor din Bucuresti. Sa
sorteze vectorul dupa pret/ nr angajati.
3. Sa afiseze doar imobilele de inchiriat/ firmele cu capital strain de pe strada
Florilor
*/
int main(int argc, char** argv) {
	Adresa ad();
	Imobil i();
	/*
		Explicatie: 
			In clasa Imobil se folosec metodele din clasa Adresa in urmatoarele functii:
				1. Constructori pentru initializarea variabilei "a" [constructori, copiere, operatorul =]
				2. Operatorul << unde folesc propriul operator deja implementat al clasei Adresa
	*/
	int n = 5;
	Imobil *buc = new Imobil[n];
	Imobil *flori = new Imobil[n];
	
	for(int i = 0; i < n; ++i)
	{
		// Populez cu valori
		char text[] = {"Calea Florilor"};
		Adresa x(text, i*2);
		Imobil tmp(x, "Cu de toate", 10 * i, (i%2 == 0)? true : false);
		buc[i] = tmp;
	}
	//cout << endl << "-----"<< endl;
	for(int i = 0; i < n; ++i)
	{
		cout << buc[i];
	}
	
	// sortare dupa pret
	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			if(buc[i].pr() < buc[j].pr() )
			{
				Imobil tmp(buc[i]);
				buc[i] = buc[j];
				buc[j] = tmp;
			}
		}
	}

	// sortare dupa nr locuitori
	for(int i = 0; i < n; ++i)
	{
		for(int j = i + 1; j < n; ++j)
		{
			if(buc[i].loc() < buc[j].loc() )
			{
				Imobil tmp(buc[i]);
				buc[i] = buc[j];
				buc[j] = tmp;
			}
		}
	}
	cout << endl << "+------------+"<< endl;
	// Cautam firme cu capital strain de pe strade florilor
	int k = 0;
	
	for(int i = 0; i < n; ++i)
	{
		// verific strada
		if(strstr(buc[i].adr() , "Florilor") != NULL && buc[i].liber())
		{
			flori[k] = buc[i];
			k++;
		}
	}
	
	for(int i = 0; i < k; ++i)
	{
		cout << flori[i];
	}
	
	delete buc;
	delete flori;
	return 0;
}
