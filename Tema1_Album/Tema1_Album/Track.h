#pragma once


class Track
{
protected:
	char * nume;
	unsigned int pozitie;

public:
	Track();
	Track(char * &);
	Track(char * &, const int &);
	Track(const Track &);
	Track& operator=(const Track &);
	void modifica(const int &);
	void modifica(char *);
	void modifica(const int &, char *);
	friend ostream& operator<<(ostream&, const Track&);
	virtual ~Track();
};

