// Tema2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ansamblu.h"
#include "Piesa_A.h"
#include "Piesa_B.h"

int main()
{
	const int n = 3;
	Object ** v = new Object*[n];

	// ADAUG VALORI
	char cod[][4] = { "104", "201" };
	char culoare[][10] = { "albastru", "rosu" };
	for (int i = 0; i < n; ++i)
	{
		if (i % 2 == 0) {
			//Piesa_A a(cod[0], i * 30, i);
			v[i++] = new Piesa_A(cod[0], (i+1) * 30, i + 1);
			//Piesa_B b(cod[0], i * 10, culoare[0]);
			v[i++] = new Piesa_B(cod[0], (i+1) * 10, culoare[0]);
		}

		Piesa_A a(cod[1], i * 2, (i + 1));
		Piesa_B * vec = new Piesa_B[i+1];
		for (int j = 0; j < (i+1); ++j)
		{
			Piesa_B b(cod[1], i * 5, culoare[1]);
			vec[j] = b;
		}

		Ansamblu tmp(a, vec);
		v[i] = new Ansamblu(a, vec);

		delete[] vec;
	}
	cout << "[!] Valori Adaugate!\n";
	// SORTARE
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (v[i]->getPret() < v[j]->getPret())
			{
				Object* tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	cout << "[!] Sortare Efectuata!\n";
	// AFISARE
	for (int i = 0; i < n; ++i)
	{
		v[i]->afisare();
		cout << "+-------------------+\n";
	}
	cout << "[!] Afisare Efectuata!\n";
	delete[] v;
	system("pause");
    return 0;
}

