#pragma once
#include <vector>
#include "Track.h"

class Album
{
protected:
	int an;
	char * nume;
public:
	vector <Track> lista;

	Album();
	Album(char *&,const int&);
	Album(char *&, const int&, vector <Track> &);
	Album(const Album &);
	void Modifica(char *&, const int&);
	void SetLista(const vector <Track> &);
	void AdaugaTrack(const Track&);
	void AdaugaTrack(char * &, const int &);
	void ModificaTrack(const int&, const Track&);
	void ModificaTrack(const int&, char *&);
	void StergeTrack(const int&);
	Album& operator= (const Album &);
	friend ostream& operator<<(ostream&, const Album&);
	friend bool operator<(const Album &, const Album &);
	friend bool operator<=(const Album &, const Album &);
	friend bool operator>(const Album &, const Album &);
	friend bool operator>=(const Album &, const Album &);
	virtual ~Album();
};

