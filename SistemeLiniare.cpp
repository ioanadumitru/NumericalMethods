#include "SistemeLiniare.h"
#include<iostream>

void SistemLiniar::GaussMethod(vector<vector<double>> matriceSistem, vector<double> termeniLiberi)
{
	vector<vector<double>> matriceExtinsa;

	for (int i = 0; i < matriceSistem.size(); i++)
	{
		vector<double> l;
		for (int j = 0; j < matriceSistem[i].size(); j++)
			l.push_back(matriceSistem[i][j]);
		matriceExtinsa.push_back(l);
	}

	for (int i = 0; i < termeniLiberi.size(); i++)
		matriceExtinsa[i].push_back(termeniLiberi[i]);
	
	int n = matriceExtinsa[0].size();
	int **aux = new int*[n];
	for (int i = 0; i < n; i++)
		aux[i] = new int[n];

	int k = 0;

	while (k < n)
	{
		int pivot = matriceExtinsa[k][k];

		if (pivot != 0)
		{
			for (int i = 0; i < matriceExtinsa.size(); i++)
			{
				for (int j = 0; j < matriceExtinsa[i].size(); j++)
				{
					if (k == i)
					{
						aux[k][j] = matriceExtinsa[k][j];
						if (k == j)
							aux[k][k] = matriceExtinsa[j][k];
						else
							aux[j][k] = 0;
					}
					else
						aux[i][j] = pivot * matriceExtinsa[i][j] - matriceExtinsa[i][k] * matriceExtinsa[k][j];
				}
			}

			for (int i = 0; i < n-1; i++)
			{
				for (int j = 0; j < n; j++)
				{
					matriceExtinsa[i][j] = aux[i][j];
				}
			}
		}
		k++;
	}
	
	for (int i = 0; i < n; i++)
		delete[] aux[i];
	delete aux;

	for (int i = 0; i < n; i++)
	{
		if (matriceExtinsa[i][i] != 0)
		{
			double rez = matriceExtinsa[i][n-1] / matriceExtinsa[i][i];
			cout << "x" << i + 1 << " = " << rez << endl;
		}
	}
}

double SistemLiniar::CalculDeterminantDeOrdin3(vector<vector<double>> a)
{
	double det = a[0][0] * a[1][1] * a[2][2] + a[1][0] * a[2][1] * a[0][2] + a[2][0] * a[1][1];

	return det;
}

int SistemLiniar::RangMatrice(vector<vector<double>> a)
{
	int coloane = a[0].size();
	int linii = a.size();
	int **aux = new int*[linii];
	for (int i = 0; i < coloane; i++)
		aux[i] = new int[coloane];
	int k = 0; 

	while (k < linii)
	{
		int pivot = a[k][k];
		if (pivot != 0)
			aux[k][k] = 1;
		
		for (int i = k + 1; i < coloane; i++)
		{
			aux[k][i] = 0;
			aux[i][k] = 0;
		}
		
		for (int it = k + 1; it < linii; it++)
		{
			for (int j = it; j < coloane; j++)
			{
				aux[it][j] = pivot * a[it][j] - a[it][k] * a[it][k];
			}
		}
		
		for (int i = 0; i < linii; i++)
		{
			for (int j = 0; j < coloane; j++)
				a[i][j] = aux[i][j];
		}
		k++;
	}
	return 0;
}

void SistemLiniar::GaussElimination(vector<vector<double>> matSistem, vector<double> termeniLiberi)
{
	vector<vector<double>> matExtinsa;

	int n = matSistem.size();
	for (int i = 0; i < n; i++)
	{
		matExtinsa.push_back(matSistem[i]);
		matExtinsa[i].push_back(termeniLiberi[i]);
	}
	//
	for (int i = 0; i < n-1; i++)
	{
		int pivot = matExtinsa[i][i];
		for (int j = i+1; j < matExtinsa.size(); j++)
		{
			int m = matExtinsa[j][i]/pivot*(-1);
			for (int k = i; k < matExtinsa[j].size(); k++)
				matExtinsa[j][k] = matExtinsa[j][k] + m*matExtinsa[i][k];
		}
	}

	vector<double> solutie;
	//calculare solutie;
	solutie.push_back(matExtinsa[n][matExtinsa.size()] / matExtinsa[n][n]);
	int m = matExtinsa.size() - 1;
	for (int i = m-1; i >= 0; i--)
	{
		int s = matExtinsa[m][m];
		for (int j = i; j < matExtinsa.size(); j++)
		{
			s -= matExtinsa[i][j];
		}
	}

}
