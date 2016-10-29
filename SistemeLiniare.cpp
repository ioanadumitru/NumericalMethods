#include "SistemeLiniare.h"
#include<iostream>

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
