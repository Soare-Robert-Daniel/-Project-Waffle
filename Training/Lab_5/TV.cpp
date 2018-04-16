#include "TV.h"

TV::TV()
{
	
}


TV::TV(char *c, int p, char *m, int d, char * i):Electrocasnice(c, p, m),diagonala(d)
{
	info_sup = new char[strlen(i)];
	strcpy(info_sup, i);
}

TV::TV(const TV &a)
{
	*this = a;
}

TV & TV::operator= (const TV &tmp)
{
	if(this != &tmp) {
		if (tmp.marca==NULL)
			this->marca=NULL;
		else {
			this->marca = new char[strlen(tmp.marca)+1];
			strcpy(this->marca,tmp.marca);
		}
		
	
		strcpy(this->cod , tmp.cod);
			
		
		if (tmp.info_sup==NULL)
			this->info_sup=NULL;
		else {
			this->info_sup = new char[strlen(tmp.info_sup)+1];
			strcpy(this->info_sup, tmp.info_sup);
		}
		
		this->pret = tmp.pret;
		this->diagonala = tmp.diagonala;
	}
	return *this;
}

void TV::afisare()
{
	Electrocasnice::	afisare();
	cout << "| Diagonala: " << diagonala << " inch | Informatii suplimentare: " << info_sup << " \n";
}


TV::~TV()
{
	delete info_sup;
}

char * TV::GetMarca()
{
	char * tmp = new char[strlen(marca)];
	strcpy(tmp, marca);
	return tmp;
}

char * TV::GetCod()
{
	char * tmp = new char[strlen(cod)];
	strcpy(tmp, cod);
	return tmp;
}


char * TV::GetInfo()
{
	char * tmp = new char[strlen(info_sup)];
	strcpy(tmp, info_sup);
	return tmp;
}


int TV::GetPret()
{
	return pret;
}

int TV::GetDiag()
{
	return diagonala;
}


