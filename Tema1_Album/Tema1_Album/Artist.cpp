#include "stdafx.h"
#include "Artist.h"

#pragma warning(disable : 4996)
Artist::Artist()
{
}

Artist::Artist(char * & nume, const int & varsta) : Persoana(nume, varsta)
{
}

Artist::Artist(char * & nume, const int & varsta,  vector<Album> & albume) : Persoana(nume, varsta)
{
	this->albume = albume;
}

Artist::Artist(const Artist & tmp)
{
	this->nume = NULL;
	*this = tmp;
}

Artist & Artist::operator=(const Artist & tmp)
{
	if (this != &tmp)
	{
		if (tmp.nume != NULL)
		{
			this->nume = new char[strlen(tmp.nume) + 1];
			strcpy(this->nume, tmp.nume);
		}
		else this->nume = NULL;
		this->varsta = tmp.varsta;
		this->albume = tmp.albume;
	}
	return *this;
}

void Artist::Modifica(char *& nume, const int & varsta)
{
	
		if (nume != NULL)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else this->nume = NULL;
		this->varsta = varsta;
	
}

void Artist::ModificaAlbum(const int & index, const Album & album)
{
	this->albume[index] = album;
}

void Artist::AdaugaAlbum(const Album & album)
{
	this->albume.push_back(album);
}

void Artist::StergeAlbum(const int & index)
{
	// [!] indexarea se face de la 0
	this->albume.erase(this->albume.begin() + index);
}

void Artist::Sortare()
{
	// sortare in ordine descrescatoare
	for(unsigned int i = 0; i < this->albume.size(); ++i)
		for (unsigned int j = i + 1; j < this->albume.size(); ++j)
		{
			if (this->albume[i] < this->albume[j])
				swap(this->albume[i], this->albume[j]);
		}
}
// SCRIE IN FISIER
void Artist::ScriereFisier()
{
	ofstream os("out.txt");
	this->Sortare();
	os << this->nume << '\n';
	for (int i = 0; i < this->albume.size(); ++i)
	{
		os << this->albume[i] << "\n";
	}
	os.close();
}

void Artist::Discografie()
{
	
	if (this->albume.size() == 0)
		return;
	for (int i = 0; i < this->albume.size(); ++i)
	{
		cout << i << ". " << this->albume[i] << ":\n";
		if (this->albume[i].lista.size() == 0)
			continue;
		for (int j = 0; j < this->albume[i].lista.size(); ++j)
		{
			cout << "		" << j << ") " << this->albume[i].lista[j] << '\n';
		}
	}
	
}


Album&  Artist::AlbumID(const int & index)
{
	return albume[index];
}

Artist::~Artist()
{
}

ostream & operator<<(ostream & os, const Artist & tmp)
{
	os << tmp.nume << " [" << tmp.varsta << "]";
	return os;
}
