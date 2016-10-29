#pragma once
#include<vector>
using namespace std;

class SistemLiniar
{
public:
	static void GaussMethod(vector<vector<double>> matriceSistem, vector<double> termeniLiberi);
	static double CalculDeterminantDeOrdin3(vector<vector<double>> matriceSistem);
	static int RangMatrice(vector<vector<double>> matriceSistem);
	static void GaussElimination(vector<vector<double>> matSistem, vector<double> termeniLiberi);
};