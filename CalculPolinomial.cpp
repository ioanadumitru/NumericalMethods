#include "CalculPolinomial.h"

vector<double> CalculEcuatii::MetodaBisectiei(vector<vector<double>> a, vector<double> sol)
{
	vector<vector<double>> mat;

	for (int i = 0; i < a.size(); i++)
	{
		mat.push_back(a[i]);
		mat[i].push_back(sol[i]);
	}

	for (int i = 0; i < a.size()-1; i++)
	{
		
		for (int j = i+1; j < mat.size(); j++)
		{
			double m2 = mat[j][i] / a[i][i];

			for (int k = j; k < mat[j].size(); k++)
				mat[j][k] = mat[j][k] - m2*mat[i][k];
		}
	}


	return vector<double>();
}
