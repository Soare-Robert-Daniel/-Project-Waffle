#pragma once
#include "Persoana.h"
#include "Album.h"
class Artist :
	public Persoana
{

public:
	vector <Album> albume;

	Artist();
	Artist(char * &, const int &);
	Artist(char * &, const int &,vector <Album> &);
	Artist(const Artist &);
	Artist& operator= (const Artist&);
	void Modifica(char * &, const int &);
	void ModificaAlbum(const int &, const Album &);
	void AdaugaAlbum(const Album &);
	void StergeAlbum(const int &);
	void Sortare();
	void ScriereFisier();
	void Discografie();
	Album& AlbumID(const int &);
	friend ostream & operator<<(ostream &, const Artist&);
	virtual ~Artist();
};

