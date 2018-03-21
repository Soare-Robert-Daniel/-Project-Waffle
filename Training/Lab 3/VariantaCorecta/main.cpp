#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Fractie {
    int numitor;
    int numarator;

public:
    Fractie();
    Fractie(int, int);
    Fractie(const Fractie&);
    Fractie& operator= (const Fractie&);
    friend const Fractie& operator+ (const Fractie& a, const Fractie& b) const;
    friend const Fractie& operator- (const Fractie& a, const Fractie& b) const;
    friend const Fractie& operator/ (const Fractie& a, const Fractie& b) const;
    friend const Fractie& operator*(const Fractie& a, const Fractie& b) const;
    Fractie& operator+= (const Fractie&);
    Fractie& operator*=  (const Fractie&);
    Fractie& operator-= (const Fractie&);
    Fractie& operator/= (const Fractie&);
    friend bool operator< (const Fractie& a, const Fractie& b) const;
    friend bool operator> (const Fractie& a, const Fractie& b) const;
    friend bool operator<= (const Fractie& a, const Fractie& b) const;
    friend bool operator>= (const Fractie& a, const Fractie& b) const;
    float get_valoare();
};


Fractie::Fractie()
{
	numitor = 1;
	numarator = 0;
}

Fractie::Fractie(int a, int b)
{
	numitor = a;
	numarator = b;
}

Fractie::Fractie(const Fractie& f)
{
	numitor = f.numitor;
	numarator = f.numarator;
}

Fractie& Fractie::operator= (const Fractie&)
{

}

int main(int argc, char** argv) {
	return 0;
}


