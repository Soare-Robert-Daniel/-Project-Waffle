#ifndef ADRESA_H
#define ADRESA_H
#include <iostream>
#include <string.h>
using namespace std;

class Adresa {
	private:
		char* str;
		int nr;
	public:
		Adresa();
		Adresa(char* c, int n);
		Adresa(const Adresa&p) ;
		Adresa& operator=(const Adresa &p) ;
		~Adresa() ;
		friend ostream& operator<<(ostream &dev,const Adresa &p);
		
		// pt celelalte cerinte
		int loc() const;
		char * adr() const;

};

#endif
