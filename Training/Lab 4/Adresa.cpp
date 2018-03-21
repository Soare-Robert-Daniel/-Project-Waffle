#include "Adresa.h"


Adresa::Adresa() {
}

Adresa::Adresa(char* c, int n):nr(n) { //se apeleaza pseudoconstructorul pentru nr de tip int;
//pseudoconstructorii se folosesc pentru initializarea tipurilor de date de baza
	if (c==NULL)
		str=NULL;
	else {
		str=new char[strlen(c)+1];
		strcpy(str,c);
	}
}

Adresa::Adresa(const Adresa&p) {
	str=NULL;
	*this=p; //reutilizez codul scris in operator=
}

Adresa& Adresa::operator=(const Adresa &p) {
	if(this!=&p) {
		if (str!=NULL) delete [] str;
		str=new char[strlen(p.str)+1];
		strcpy(str, p.str);
		nr=p.nr;
	}
	return *this;
}

Adresa::~Adresa() {
	if (str!=NULL) delete[]str;
}

ostream& operator<<(ostream &dev,const Adresa &p) {
// in operatorul de << din
//Carte se foloseste operatorul de << din Pagina
	if (p.str!=NULL) dev<<"Strada: "<<p.str<<endl;
	dev<<"Nr. : "<<p.nr<<endl<<endl;
}

int Adresa::loc() const
{
	return this->nr;
}

char * Adresa::adr() const
{
	return this->str;
}


