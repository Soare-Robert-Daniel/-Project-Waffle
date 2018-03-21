#include "Imobil.h"

Imobil::Imobil()
{
	
}

Imobil::Imobil(const Adresa& ad, char* descriere, int p, bool d):a(ad), pret(p), de_inchiriat(d)
{
	if (descriere==NULL)
		this->descriere=NULL;
	else {
		this->descriere = new char[strlen(descriere)+1];
		strcpy(this->descriere,descriere);
	}
}

Imobil::Imobil(const Imobil& i)
{
	this->descriere = NULL;
	*this = i;  //reutilizez codul scris in operator= (ca in Adresa)
}

Imobil & Imobil::operator= (const Imobil& i)
{
	if(this !=& i) {
		if (i.descriere==NULL)
			this->descriere=NULL;
		else {
			this->descriere = new char[strlen(i.descriere)+1];
			strcpy(this->descriere,i.descriere);
		}
		this->a = i.a;
		this->pret = i.pret;
		this->de_inchiriat = i.de_inchiriat; 
	}
	return *this;
}

ostream& operator<<(ostream &dev,const Imobil &i) {
	if (i.descriere !=NULL) dev<<"Descriere: "<<i.descriere<<endl;
	dev<<"Pret : "<<i.pret << " lei"<<endl << "Inchiriat: "<< i.de_inchiriat << endl;
	dev<<i.a;
}

Imobil::~Imobil()
{
	if(this->descriere != NULL)
	{
		delete []this->descriere;
	}	
}

int Imobil::pr() const
{
	return this->pret;
}

int Imobil::loc() const
{
	return this->a.loc();
}

char * Imobil::adr() const
{
	return this->a.adr();
}

bool Imobil::liber() const
{
	return this->de_inchiriat;
}
