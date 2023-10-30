#include <iostream>
#include <math.h>
//using namespace std;

/*struct Informer
{
	Informer() { std::cout << "stworzony!\n"; }
	~Informer() { std::cout << "zniszczony :C\n"; }
};*/

class Wektor2D
{
	Wektor2D(double x_init, double y_init)
	{
		x = x_init;
		y = y_init;
		
		std::cout << "Stworzony: ";
		print();
	}
	
	Wektor2D()
	{
		x = 0.0;
		y = 0.0;
	}
	
	~Wektor2D()
	{
		std::cout << "Zniszczony: ";
		print();
	}
	
	double x;
	double y;
	
	//Informer info;
	
public:
	void setX(double val) { x = val; }
	void setY(double val) { y = val; }
	double getX() { return x; }
	double getY() { return y; }
	
	void print() { std::cout << "x = " << x << ", y = " << y << "\n"; }
	double norm() { return sqrt(x*x + y*y); }
};

Wektor2D operator+(Wektor2D & v1, Wektor2D & v2)
{
	return Wektor2D
	{
		v1.getX() + v2.getX(),
		v1.getY() + v2.getY()
	};
}

double operator*(Wektor2D & v1, Wektor2D & v2)
{
	return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}

std::ostream & operator<<(std::ostream & os, Wektor2D & v)
{
	os << "x=" << v.getX() << ", y=" << v.getY() << "\n";
	return os;
}