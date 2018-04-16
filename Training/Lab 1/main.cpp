#include <iostream>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
TASK	:
	1.scrieti functiile structurii
	2.creeaza un vector, pune valori si sorteaza dupa medii, apoi testeaza toate functiile
*/
using namespace std;
struct Student{
	private:
		int id;
		char * nume;
		char nume_grupa[5];
		int note_sem_2i[5];
	public:
		void init();
		void afis() const;
		void modifica(const char[]); // modifica seria si grupa
		void modifica(const Student &); // copiere
		void modifica(int , int); // (pozitie, nota)
		float getMedieSem() const;
};
// ------------------------------------------------ Task 1 ----------------------------------------------
void Student::init()
{
	// pune valori aleatorii
	id = 0;
	
	nume = new char[25];
	strcpy(nume,"Gica Strungarul");
	
	strcpy(nume_grupa, "1311");
	
	for(int i = 0; i < 5; ++i)
		note_sem_2i[i] = 0;
}

void Student::afis() const
{
	cout << "ID: " << id << '\n';
	cout << "Nume: " << nume << '\n';
	cout << "Grupa: " << nume_grupa << '\n';
	cout << "Note: ";
	for(int i = 0; i < 5; ++i)
		cout << note_sem_2i[i] << " ";
	cout << "\n\n";
}

void Student::modifica(const char nnume[])
{
	strcpy(nume, nnume); // strcpy(destinatie, sursa)
}

void Student::modifica(const Student & poli)
{
	// iau datele in poli si le pun pe aceasta structura
	id = poli.id;
	strcpy(nume, poli.nume);
	strcpy(nume_grupa, poli.nume_grupa);
	for(int i = 0; i < 5; ++i)
		note_sem_2i[i] = poli.note_sem_2i[i];
}

void Student::modifica(int poz, int nota) // (pozitia notei, nota)
{
	note_sem_2i[poz] = nota;
}

float Student::getMedieSem() const
{
	int suma = 0;
	for(int i = 0; i < 5; ++i)
		suma += note_sem_2i[i];
	return suma/5.0;
}

// ------------------------------------------------ End ----------------------------------------------

int main(int argc, char** argv) {
	/*
	Intr-o zi vreau sa am mare Panamera gold
	Jante d-alea agresive si lasate jos de tot
	Zi ce vrei,am mare plan,genti de bani,sunt golan
	Am o minte geniala,nu vreau munca la program
	Fac eu cumva si tot imi iese bine,am incredere in mine
	Stiu de ce sunt in stare
	Ti-am promis mama,ma intorc tot acasa
	Cand o sa cresc mare o sa fiu cel mai tare
	Cu toata brigada,mereu sunt loiali
	Baiatu de aur,am flow-ul regal
	Dau sa ies invingator,asta e scopul meu principal
	Daca o sa cad ma ridic,nu ma opreste nimic
	Panamera fug ca pantera schimb temperatura
	Las in spate ura,cliqua e fow
	Lino se baga,ia tot
	Poti sa faci mare raport,NOS-u' si MOTORSPORT
	*/
	cout << "+---------------- [!] Phase 1 -------------------+\n";
	Student * studenti = new Student[4];
	cout << "+---------------- [!] Phase 2 -------------------+\n";
	for(int i = 0; i < 4; ++i)
	{
		cout << "[#] ID: " << i << '\n';
		studenti[i].init();
		cout << "[*] Phase 2 sub 1 \n";
		if(i & 1)
			studenti[i].modifica("Panamera");
			/*
			Vreau sa-mi iau un Panamera
			*/
		else
			studenti[i].modifica("Pantera");
			/*
			S-alerg noaptea ca pantera
			*/
		cout << "[*] Phase 2 sub 2 \n";
		for(int j = 0; j < 5; ++j)
			studenti[i].modifica(j, i + j);
		cout << "[*] Phase 2 sub 3 \n";
		/*
		Sa ma pierd usor in noapte
		Foc ca din pusca mitraliera	
		*/
	}
	cout << "+---------------- [!] Phase 3 -------------------+\n";
	studenti[3].modifica(studenti[2]);
	cout << "+---------------- [!] Phase 4 -------------------+\n";
	for(int i = 0; i < 4; ++i)
	{
		studenti[i].afis();
		cout << "Medie: " << studenti[i].getMedieSem() << "\n\n";	
	}	
	cout << "+---------------- [!] Phase 5 -------------------+\n";
	for(int i = 0; i < 4; ++i)
	{
		for(int j = i+1; j < 4; ++j)
			if(studenti[i].getMedieSem() > studenti[j].getMedieSem())
				{
					Student tmp;
					tmp.modifica(studenti[i]);
					studenti[i].modifica(studenti[j]);
					studenti[j].modifica(tmp);
				}
	}
	cout << "+---------------- [!] Phase 6 -------------------+\n";
	for(int i = 0; i < 4; ++i)
	{
		studenti[i].afis();
		cout << "Medie: " << studenti[i].getMedieSem() << "\n\n";	
	}	
	cout << "+---------------- [!] Phases Completed! -------------------+\n";
	
	return 0;
}
