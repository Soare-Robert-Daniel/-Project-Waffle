#pragma once
#include "Artist.h"
class Meniu
{
protected:

	unsigned int cur_id_artist;
	unsigned int cur_id_albume;
	unsigned int cur_id_track;

	bool stopAlbum;
	bool stopArtist;

	
	void CreareArtist();
	void CreareAlbum();
	void CreareTrack();

	void ModificaArtist();
	void ModificaAlbum();
	void ModificaTrack();
	
	void MeniuArtist(const int &);
	void MeniuAlbum(const int &);
	void EfectueazaComanda(const int &);
	

public:
	vector <Artist> artisti;
	

	enum ComenziEran {
		LOGO,
		MENIU,
		STERGE,
		PATH
	};

	enum ComenziMeniu {
		INAPOI,
		VEZIARTIST,
		STERGEARTIST,
		ADAUGAARTIST,
		STOPARTIST,
		VEZIALBUM,
		STERGEALBUM,
		ADAUGAALBUM,
		STOPALBUM,
		ADAUGATRACK,
		STERGETRACK,
		MODIFICAARTIST,
		MODIFICAALBUM,
		MODIFICATRACK,
		FISIERARTIST,
		DISCOGRAFIE
	};
	Meniu();
	void MeniuPrincipal();
	void Comanda(const char *);
	void Ecran(const int &);

	int AlegeP();
	int AlegeA();
	int AlegeT();

	virtual ~Meniu();
};

