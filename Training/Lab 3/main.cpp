#include <iostream>
using namespace std;

class fractie {
    double numitor,numarator;
   public:
   	fractie(double numitor=0,double numarator=0){
	   
   	this->numitor=numitor;
   	this->numarator=numarator;
    }
    friend const fractie& operator+(const fractie& f, const fractie& g){
    	fractie c;
    	if(f.numitor=g.numitor)
    	{
    		c.numarator=f.numarator+g.numarator;
    		c.numitor=f.numitor;
    		return c;
		}
		else
		{
			c.numarator=(f.numarator*g.numitor)+(g.numarator*f.numitor);
			c.numitor=f.numitor;
			return c;
		}
	};
	friend const fractie& operator-(const fractie& f,const fractie& g){
		fractie c;
		if(f.numitor=g.numitor)
		{
			c.numitor=f.numitor-g.numitor;
			c.numarator=f.numarator;
			return c;
			
		}
	}
	
	Fractie();
    Fractie(int, int);  
	fractie(const fractie&);
    fractie& operator= (const Fractie&); 
    friend const fractie& operator+ (const fractie& a, constf ractie& b);
    friend const fractie& operator- (const fractie& a, const fractie& b);
    friend const fractie& operator/ (const fractie& a, const fractie& b);
    friend const Fractie& operator*(const Fractie& a, const Fractie& b);
    fractie& operator+= (const fractie&);
    fractie& operator*=  (const fractie&);
    fractie& operator-= (const fractie&);
    fractie& operator/= (const fractie&);
    friend bool operator< (const fractie& a, const fractie& b);
    friend bool operator> (const fractie& a, const fractie& b);
    friend bool operator<= (const fractie& a, const fractie& b);
    friend bool operator>= (const fractie& a, const fractie& b);
    float get_valoare();
  
};

