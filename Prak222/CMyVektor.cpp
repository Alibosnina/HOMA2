#include <iostream>
#include "CMyVektor.h"
using namespace std;

double CMyVektor::get_length()
{
	double length = 0;
	for (int i = 0; i < getDimension(); i++)
	{
		length += (werte[i] * werte[i]);
	}
	return sqrt(length);
}

CMyVektor operator+(CMyVektor a, CMyVektor b)
{
	CMyVektor c(a.getDimension());
	for (int i = 0; i < c.getDimension(); i++)
	{
		c.setKomp(a.getKomp(i) + b.getKomp(i), i);
	}
	return c;
}

CMyVektor operator*(double lambda, CMyVektor a)
{
	CMyVektor d(a.getDimension());
	for (int i = 0; i < d.getDimension(); i++)
	{
		d.setKomp(a.getKomp(i) * lambda, i);
	}
	return d;
}

CMyVektor operator-(CMyVektor a, CMyVektor b)
{
	CMyVektor differenz(a.getDimension());
	for (int i = 0; i < a.getDimension(); i++)
	{
		differenz.setKomp(a.getKomp(i) - b.getKomp(i), i);
	}
	return differenz;
}

CMyVektor operator/(CMyVektor a, double h)
{
	CMyVektor quotient(a.getDimension());
	for (int i = 0; i < a.getDimension(); i++)
	{
		quotient.setKomp(a.getKomp(i) / h, i);
	}
	return quotient;
}

std::ostream& operator<<(std::ostream& os, CMyVektor x)
{
	os << "(";
	int ende = x.getDimension();
	for (int i = 0; i < x.getDimension(); i++)
	{
		os << x.getKomp(i);
		if (!(i == ende - 1))
		{
			cout << "; ";
		}
	}
	os << ")";

	return os;
}

//Weckstelle ist auch dabei
CMyVektor gradient(CMyVektor x, CMyVektor(*function)(CMyVektor x), int cnt)
{
	const double h = 1e-4;
	const int dim = x.getDimension();
	CMyVektor temp(dim);
	CMyVektor grad(dim); 
	CMyVektor summe(dim);
	CMyVektor differenz(dim);

	for (int j = 0; j < dim; j++)
	{
		if (j == cnt)
		{
			temp.setKomp(x.getKomp(j) + h, j);
		}
		else
		{
			temp.setKomp(x.getKomp(j), j);
		}
	}

	summe = function(temp); //f r den Teil links von minus
	differenz = function(x); //f r den Teil rechts von minus
	grad = (summe - differenz) / h; //Eintrag von Gradient berechnen DIFFERENZQUOTIENT
	return grad;
}