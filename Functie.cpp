#include "Functie.h"
#include<iostream>
using namespace std;

FunctiePolinomiala FunctiePolinomiala::Derivare()
{
	multimap<int, int> functieDerivata;
	multimap<int, int>::iterator it;

	for (it = functie.begin(); it != functie.end(); it++)
	{
		if ((*it).first == 0)
			functieDerivata.insert(make_pair(0, 0));
		if ((*it).first == 0 && (*it).second != 0)
			functieDerivata.insert(make_pair(0, 0));
		else
			functieDerivata.insert(make_pair((*it).first - 1, (*it).first * (*it).second));
	}

	return FunctiePolinomiala(functieDerivata);
}


FunctiePolinomiala::FunctiePolinomiala()
{

}

FunctiePolinomiala::FunctiePolinomiala(multimap<int, int> f)
{
	functie = f;
}

void FunctiePolinomiala::AddMembru(int putere, int coeficient)
{
	functie.insert(make_pair(putere, coeficient));
}

void FunctiePolinomiala::AfisareFunctie()
{

	multimap<int, int>::iterator it = functie.begin();
	int i = 0;
	for (; it != functie.end(); it++)
	{
		if ((*it).second == 0 && (*it).first == 0)
			cout << "0";
		if ((*it).second > 0)
			cout << "+" << (*it).second << "*x^" << (*it).first;
		else if ((*it).second != 0)
			cout << (*it).second << "*x^" << (*it).first;
		i++;
	}

	cout << endl;
}

double FunctiePolinomiala::f(double a)
{
	double rez = 0;
	for (auto it = functie.rbegin(); it != functie.rend(); it++)
	{
		rez += it->second * pow(a, it->first);
	}

	return rez;
}

double FunctiePolinomiala::MetodaTangentei(double x, int iteratii)
{
	FunctiePolinomiala fderivat = this->Derivare();
	fderivat.AfisareFunctie();

	int i = 0;
	while (i != iteratii)
	{
		double  rez1 = this->f(x);
		double rez2 = fderivat.f(x);

		x = (x)-(rez1 / rez2);
		i++;
	}

	return x;
}

double FunctiePolinomiala::MetodaBisectiei(double a, double b, double epsilon)
{
	double xm = (a + b) / 2;
	double fxm = this->f(xm);

	while (abs(fxm) > epsilon)
	{
		xm = (a + b) / 2;
		fxm = this->f(xm);
		double fa = this->f(a);
		double fb = this->f(b);

		if (fa * fxm < 0)
			b = xm;
		else 
			if (fb*fxm < 0)
				a = xm;
	}
	 
	return xm;
}

double FunctiePolinomiala::MetodaSecantei(double x1, double x2, double epsilon)
{

	while (abs(f(x2)) > epsilon)
	{
		double f2 = this->f(x2);
		double f1 = this->f(x1);

		double x = x1;
		x1 = x2;
		x2 = x2 - (f2 *(x2 - x) / (f2 - f1));
	}

	return x2;
}

