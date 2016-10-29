#pragma once
#include<map>
#include<math.h>
using namespace std;

class FunctiePolinomiala
{
	float x;
	multimap<int, int> functie; //power, coeficient
public:
	FunctiePolinomiala();
	FunctiePolinomiala(multimap<int, int> f);
	void AddMembru(int coeficient, int putere);
	FunctiePolinomiala Derivare();
	void AfisareFunctie();
	double f(double a);
	double MetodaTangentei(double x1, int iteratii); // Newton-Raphson
	double MetodaBisectiei(double a, double b, double epsilon);
	double MetodaSecantei(double x1, double x2, double epsilon);

};