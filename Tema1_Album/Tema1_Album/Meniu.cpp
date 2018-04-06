#include "stdafx.h"
#include "Meniu.h"


void Meniu::CreareArtist()
{
	// VARIABILE
	char * nume = new char[50];
	int varsta = -1;

	// ATRIBUIRI
	cout << "Adauga artist:\n";
	cout << "	  Nume: "; cin >> nume;
	cout << "	Varsta: "; cin >> varsta;

	// ADAUGARE & OPTIUNI ECRAN
	Artist tmp(nume, varsta);
	this->artisti.push_back(tmp);

	if(nume != NULL)
		delete nume;
}

void Meniu::CreareAlbum()
{
	char * nume = new char[50];
	int an = -1;

	// ATRIBUIRI
	cout << "Adauga album:\n";
	cout << "	  Nume: "; cin >> nume;
	cout << "	    An: "; cin >> an;

	// ADAUGARE & OPTIUNI ECRAN
	Album tmp(nume, an);
	this->artisti[this->cur_id_artist].AdaugaAlbum(tmp);

	if (nume != NULL)
		delete nume;
}

void Meniu::CreareTrack()
{
	char * nume = new char[50];

	// ATRIBUIRI
	cout << "Adauga track:\n";
	cout << "	  Nume: "; cin >> nume;
	

	// ADAUGARE & OPTIUNI ECRAN
	Track tmp(nume);
	//this->artisti[this->cur_id_artist].albume[this->cur_id_albume].AdaugaTrack(tmp); - probleme cu citirea
	this->artisti[this->cur_id_artist].albume[this->cur_id_albume].AdaugaTrack(nume, -1);
	if (nume != NULL)
		delete nume;
}

void Meniu::ModificaArtist()
{
	// VARIABILE
	char * nume = new char[50];
	int varsta = -1;

	// ATRIBUIRI
	cout << "Adauga artist:\n";
	cout << "	  Nume: "; cin >> nume;
	cout << "	Varsta: "; cin >> varsta;

	// ADAUGARE & OPTIUNI ECRAN
	
	this->artisti[this->cur_id_artist].Modifica(nume, varsta);

	if (nume != NULL)
		delete nume;
}

void Meniu::ModificaAlbum()
{
	char * nume = new char[50];
	int an = -1;

	// ATRIBUIRI
	cout << "Adauga album:\n";
	cout << "	  Nume: "; cin >> nume;
	cout << "	    An: "; cin >> an;

	// ADAUGARE & OPTIUNI ECRAN
	Album tmp(nume, an);
	this->artisti[this->cur_id_artist].albume[this->cur_id_albume].Modifica(nume, an);

	if (nume != NULL)
		delete nume;
}

void Meniu::ModificaTrack()
{
	char * nume = new char[50];

	// ATRIBUIRI
	cout << "Adauga track:\n";
	cout << "	  Nume: "; cin >> nume;


	// ADAUGARE & OPTIUNI ECRAN
	Track tmp(nume);
	//this->artisti[this->cur_id_artist].albume[this->cur_id_albume].AdaugaTrack(tmp); - probleme cu citirea
	this->artisti[this->cur_id_artist].albume[this->cur_id_albume].ModificaTrack(this->cur_id_track,nume);
	if (nume != NULL)
		delete nume;
}

void Meniu::MeniuPrincipal()
{
	Ecran(STERGE);
	Ecran(LOGO);
	bool er = false;
	this->cur_id_artist = -1;
	// AFISEAZA ARTISTII
	do {

		cout << "Lista cu artisti:\n";
		for (unsigned int i = 0; i < this->artisti.size(); ++i)
			cout << "	" << i << ") " << this->artisti[i] << "      Nr. albume " << this->artisti[i].albume.size() << '\n';
		//if (er)
		//	cout << "Date introduse gresit! M-ai incercati!";
		cout << "Comenzi disponibile: vezi, adauga, modifica, sterge\n";
		this->EfectueazaComanda(this->AlegeP());
		
		//else er = true;
		Ecran(STERGE);
		Ecran(LOGO);
			
	} while (true);
}

void Meniu::MeniuArtist(const int & index)
{
	this->cur_id_albume = -1;
	this->stopArtist = false;
	Ecran(MENIU);

	bool er = false;
	// AFISEAZA ALBUME
	do {

		cout << "Lista cu albume:\n";
		if (this->artisti[index].albume.size() > 0)	
			for (unsigned int i = 0; i < this->artisti[index].albume.size(); ++i)
				cout << "	" << i << ") " << this->artisti[index].AlbumID(i) << "      Nr. track-uri: " << this->artisti[index].AlbumID(i).lista.size() << '\n';
		//if (er)
		//	cout << "Date introduse gresit! M-ai incercati!";
		cout << "Comenzi disponibile: vezi, adauga, modifica, sterge, fisier, discografie, inapoi\n";
		this->EfectueazaComanda(this->AlegeA());
		
		//else er = true;

		this->cur_id_albume = -1;
		Ecran(MENIU);
		
	} while (!this->stopArtist);
}

void Meniu::MeniuAlbum(const int & index)
{
	Ecran(MENIU);
	this->cur_id_track = -1;
	bool er = false;
	this->stopAlbum = false;
	// AFISEAZA Track-uri
	do {

		int id = -1;
		cout << "Lista cu track-uri:\n";
		if(this->artisti[this->cur_id_artist].albume[index].lista.size() > 0)
			for (unsigned int i = 0; i < this->artisti[this->cur_id_artist].albume[index].lista.size(); ++i)
				cout << "	" << i << ") " << this->artisti[this->cur_id_artist].AlbumID(index).lista[i] << '\n';
		//if (er)
		//	cout << "Date introduse gresit! M-ai incercati!";
		cout << "Comenzi disponibile: adauga, modifica, sterge, inapoi\n";
		this->EfectueazaComanda(this->AlegeT());
		//else er = true;

		this->cur_id_track = -1;
		Ecran(MENIU);
		
		//cout << "Inca nu fost implementat!";
	} while (!this->stopAlbum);
}

void Meniu::EfectueazaComanda(const int & comanda)
{
	switch(comanda)
	{
	case INAPOI:
		if (this->stopAlbum == false)
			this->stopAlbum = true;
		else if (this->stopArtist == false)
			this->stopArtist = true;
		break;
	case VEZIARTIST:
		this->MeniuArtist(this->cur_id_artist);
		break;
	case STERGEARTIST:
		this->artisti.erase(this->artisti.begin() + this->cur_id_artist);
		//cout << "Inca nu fost implementat!";
		break;
	case ADAUGAARTIST:
		this->CreareArtist();
		break;
	case VEZIALBUM:
		this->MeniuAlbum(this->cur_id_albume);
		break;
	case STERGEALBUM:
		this->artisti[this->cur_id_artist].StergeAlbum(this->cur_id_albume);
		break;
	case ADAUGAALBUM:
		this->CreareAlbum();
		break;
	case ADAUGATRACK:
		this->CreareTrack();
		break;
	case STERGETRACK:
		this->artisti[this->cur_id_artist].albume[this->cur_id_albume].StergeTrack(this->cur_id_track);
		break;
	case MODIFICAARTIST:
		this->ModificaArtist();
		break;
	case MODIFICAALBUM:
		this->ModificaAlbum();
		break;
	case MODIFICATRACK:
		this->ModificaTrack();
		break;
	case FISIERARTIST:
		this->artisti[this->cur_id_artist].ScriereFisier();
		break;
	case DISCOGRAFIE:
		this->artisti[this->cur_id_artist].Discografie();
		system("pause");
		break;
	default:
		cout << "Comanda nu exista!";
		break;
	}
}

void Meniu::Ecran(const int & id)
{
	switch (id)
	{
	case LOGO:

		cout << "               _   _     _                          \n";
		cout << "    /\\        | | (_)   | |       /\\                \n";
		cout << "   /  \\   _ __| |_ _ ___| |_     /  \\   _ __  _ __  \n";
		cout << "  / /\\ \\ | '__| __| / __| __|   / /\\ \\ | '_ \\| '_ \\ \n";
		cout << " / ____ \\| |  | |_| \\__ \\ |_   / ____ \\| |_) | |_) |\n";
		cout << "/_/    \\_\\_|   \\__|_|___/\\__| /_/    \\_\\ .__/| .__/ \n";
		cout << "                                       | |   | |    \n";
		cout << "                                       |_|   |_|    \n";

		break;
	case STERGE:
		system("CLS");
		break;
	case PATH:
		cout << "[Locatie] Artist: " << this->artisti[this->cur_id_artist];
		if (this->cur_id_albume >= 0)
			cout << " Album: " << this->artisti[this->cur_id_artist].AlbumID(this->cur_id_albume);
		break;
	case MENIU:
		Ecran(STERGE);
		Ecran(LOGO);;
		//Ecran(PATH);
		break;
	default:
		break;
	}
}

int Meniu::AlegeP()
{
	char * s = new char[10];
	int comanda = -1;
	cout << "$ Comanda > "; cin >> s;
	if (strcmp("vezi", s) == 0)
	{
		cout << "Alege un artist (scriei id-ul): "; cin >> this->cur_id_artist;
		if (this->cur_id_artist >= 0 && this->cur_id_artist < this->artisti.size())
		{
			comanda = VEZIARTIST;
		}
		
	} else if (strcmp("sterge", s) == 0)
	{
		cout << "Alege un artist (scriei id-ul): "; cin >> this->cur_id_artist;
		if (this->cur_id_artist >= 0 && this->cur_id_artist < this->artisti.size())
		{
			comanda = STERGEARTIST;
		}
		
	}
	else if (strcmp("adauga", s) == 0)
	{
		comanda = ADAUGAARTIST;
	}
	else if (strcmp("modifica", s) == 0)
	{
		cout << "Alege un artist (scriei id-ul): "; cin >> this->cur_id_artist;
		if (this->cur_id_artist >= 0 && this->cur_id_artist < this->artisti.size())
		{
			comanda = MODIFICAARTIST;// STOPALBUM;
		}
	}
	delete s;

	return comanda;
}

int Meniu::AlegeA()
{
	char * s = new char[20];
	int comanda = -1;
	cout << "$ Comanda > "; cin >> s;
	if (strcmp("vezi", s) == 0)
	{
		cout << "Alege un album (scriei id-ul): "; cin >> this->cur_id_albume;

		// TODO: verifica daca albumul de gol si implementeaza solutia

		if (this->cur_id_albume >= 0 && this->cur_id_albume < this->artisti[this->cur_id_artist].albume.size())
		{
			comanda = VEZIALBUM;
		}
	}
	else if (strcmp("sterge", s) == 0)
	{
		cout << "Alege un album (scriei id-ul): "; cin >> this->cur_id_albume;

		// TODO: verifica daca albumul de gol si implementeaza solutia

		if (this->cur_id_albume >= 0 && this->cur_id_albume < this->artisti[this->cur_id_artist].albume.size())
		{
			comanda = STERGEALBUM;
		}
		
	}
	else if (strcmp("adauga", s) == 0)
	{
		comanda = ADAUGAALBUM;
	}
	else if (strcmp("inapoi", s) == 0)
	{
		comanda = INAPOI;//STOPARTIST;
	}
	else if (strcmp("modifica", s) == 0)
	{
		cout << "Alege un album (scriei id-ul): "; cin >> this->cur_id_albume;

		// TODO: verifica daca albumul de gol si implementeaza solutia

		if (this->cur_id_albume >= 0 && this->cur_id_albume < this->artisti[this->cur_id_artist].albume.size())
		{
			comanda = MODIFICAALBUM;// STOPALBUM;
		}
	}
	else if (strcmp("fisier", s) == 0)
	{
		comanda = FISIERARTIST;//STOPARTIST;
	}
	else if (strcmp("discografie", s) == 0)
	{
		comanda = DISCOGRAFIE;//STOPARTIST;
	}
	delete s;

	return comanda;
}

int Meniu::AlegeT()
{
	char * s = new char[10];
	int comanda = -1;
	cout << "$ Comanda > "; cin >> s;
	if (strcmp("sterge", s) == 0)
	{
		cout << "Alege un track (scriei id-ul): "; cin >> this->cur_id_track;

		// TODO: verifica daca albumul de gol si implementeaza solutia

		if (this->cur_id_track >= 0 && this->cur_id_albume < this->artisti[this->cur_id_artist].albume[this->cur_id_albume].lista.size())
		{
			comanda = STERGETRACK;
		}
	}
	else if (strcmp("adauga", s) == 0)
	{
		comanda = ADAUGATRACK;
	}
	else if (strcmp("inapoi", s) == 0)
	{
		comanda = INAPOI;// STOPALBUM;
	}
	else if (strcmp("modifica", s) == 0)
	{
		cout << "Alege un track (scriei id-ul): "; cin >> this->cur_id_track;

		// TODO: verifica daca albumul de gol si implementeaza solutia

		if (this->cur_id_track >= 0 && this->cur_id_albume < this->artisti[this->cur_id_artist].albume[this->cur_id_albume].lista.size())
		{
			comanda = MODIFICATRACK;// STOPALBUM;
		}
	}

	delete s;

	return comanda;
}

Meniu::Meniu()
{
	cur_id_artist = -1;
	cur_id_albume = -1;
	cur_id_track = -1;

	stopAlbum = true;
	stopArtist= true;

	
}

void Meniu::Comanda(const char *)
{

}


Meniu::~Meniu()
{
	
}
