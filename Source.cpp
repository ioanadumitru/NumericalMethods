#include"SistemeLiniare.h"
#include"Functie.h"
#include"CalculPolinomial.h"
#include<iostream>
int main()
{
	vector<vector<double>> mat = { {1, -2, 3, 1}, {2, -4, 1, -3}, {1, 1, -1, 4}, {4, -5, 3, 2} };
	vector<double> v = {0, 1, 3, 2};

//	SistemLiniar::GaussMethod(mat, v);
//	SistemLiniar::RangMatrice(mat);

	multimap<int, int> a;
	pair<int, int> p = make_pair(3, 1);
	a.insert(p);
	p = make_pair(2, -1);
	a.insert(p);
	p = make_pair(1, -1);
	a.insert(p);
	p = make_pair(0, 1);
	a.insert(p);
	FunctiePolinomiala f(a);

	f.AfisareFunctie();
	cout << f.MetodaTangentei(-0.2, 7) << endl;
	
	multimap<int, int> b;
	p = make_pair(3, 1);
	b.insert(p);
	p = make_pair(1, -4);
	b.insert(p);
	p = make_pair(0, 2);
	b.insert(p);


	FunctiePolinomiala f2(b);
	f2.AfisareFunctie();
	cout << f2.MetodaBisectiei(0, 1, 0) << endl;

	multimap<int, int> fg;
	p = make_pair(3, 8);
	fg.insert(p);
	p = make_pair(2, 1);
	fg.insert(p);
	p = make_pair(1, 8);
	fg.insert(p);
	p = make_pair(0, -3);
	fg.insert(p);

	FunctiePolinomiala g(fg);
	cout << g.MetodaSecantei(0.0, 0.6, 0.0001) << endl;
	cout << g.MetodaTangentei(1, 10) << endl;

	vector<vector<double>> matrice;
	vector<double> m = { 1, 1,1 };
	matrice.push_back(m);
	m = { 2, -1, 3 };
	matrice.push_back(m);
	m = { 1, 4,1 };
	matrice.push_back(m);

	vector<double> t = { 6, 9, 12 };

	CalculEcuatii::MetodaBisectiei(matrice, t);
	mat.clear();
	mat = { {1, 1,1}, {2, -1, 3}, {1, 4, 1} };
	v.clear();
	v = { 6, 9, 12 };
	SistemLiniar::GaussElimination(mat, v);

	system("pause");
	return 0;
}