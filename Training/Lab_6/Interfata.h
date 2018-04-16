#ifndef INTERFATA_H
#define INTERFATA_H

class Interfata
{
	public:
		virtual void afisare()=0 ;
		virtual ~Interfata();
		virtual float getValoare()=0;
		virtual double getVenitPeLuna()=0;
};

#endif
