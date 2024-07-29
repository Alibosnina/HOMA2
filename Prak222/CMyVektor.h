#pragma once
#include <cmath>

class CMyVektor
{
private:
	int dimension;
	double* werte;

public:
	CMyVektor(int dim) : dimension(dim) { werte = new double[dim]; }

	int getDimension() const { return dimension; }

	void setKomp(double zahl, int index) { werte[index] = zahl; }

	double getKomp(int index) { return werte[index]; }

	double get_length();
};

CMyVektor gradient(CMyVektor x, CMyVektor (*function)(CMyVektor x), int h); 

CMyVektor operator+(CMyVektor a, CMyVektor b);

CMyVektor operator*(double lambda, CMyVektor a);

CMyVektor operator-(CMyVektor a, CMyVektor b); 

CMyVektor operator/(CMyVektor a, double h); 

std::ostream& operator<<(std::ostream& os, CMyVektor x);