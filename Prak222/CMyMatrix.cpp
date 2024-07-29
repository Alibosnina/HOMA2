#include <iostream>
#include "CMyMatrix.h"
using namespace std;

CMyMatrix::CMyMatrix(int dim1, int dim2) : row(dim1), cols(dim2) {
	werte = new double*[dim1];
	for (int i = 0; i < dim1; i++)
	{
		werte[i] = new double[dim2];
	}
}

ostream& operator<<(ostream& os, CMyMatrix x)
{
	os << endl << '\t';
	for (int j = 0; j < x.getrows(); j++)
	{
		for (int i = 0; i < x.getcols(); i++)
		{
			if (i == 0)
				cout << "\t|";

			os << x.getnum(j, i);
			
			if (!(i == x.getcols() - 1))
				cout << "; ";

			if (i == x.getcols()- 1)
				cout << "|" << endl << '\t';
		}
	}
	return os;
}


CMyVektor operator*(CMyMatrix A, CMyVektor x)
{
	CMyVektor produkt(A.getrows());
	double summe = 0;
	for (int i = 0; i < A.getrows(); i++)
	{
		for (int j = 0; j < A.getcols(); j++)
		{
			summe += A.getnum(i, j) * x.getKomp(j);
		}
		produkt.setKomp(summe, i);
		summe = 0;
	}
	return produkt;
}

CMyMatrix CMyMatrix::invers()
{
	if (this->getrows() == 2 && this->getcols() == 2)
	{
		double det;
		det = this->getnum(0, 0) * this->getnum(1, 1) - this->getnum(1, 0) * this->getnum(0, 1);
		if (det != 0)
		{
			CMyMatrix a(2, 2);
			a.setnum(this->getnum(1, 1) / det, 0, 0);
			a.setnum(-(this->getnum(0, 1)) / det, 0, 1);
			a.setnum(-(this->getnum(1, 0)) / det, 1, 0);
			a.setnum(this->getnum(0, 0) / det, 1, 1);
			return a;
		}
		else
		{
			cout << "Det ist gleich null!" << endl;
		}
	}

	cout << "Das matrix ist nicht 2 x 2." << endl;
	return *this;
}

CMyMatrix jacobi(CMyVektor x, CMyVektor (*funktion)(CMyVektor x))
{
	CMyVektor f(x.getDimension()); 
	CMyMatrix j(funktion(x).getDimension(), x.getDimension());

	for (int i = 0; i < j.getcols(); i++)
	{
		f = gradient(x, funktion, i);
		for (int k = 0; k < j.getrows(); k++)
		{
			j.setnum(f.getKomp(k), k, i);
		}
	}
	return j;
}

void newtonverfahren(CMyVektor x, CMyVektor(*funktion)(CMyVektor x))

{
	int schritte = 0;
	while (schritte < 50)
	{
		CMyVektor f_von_x = funktion(x);
		CMyMatrix j(f_von_x.getDimension(), x.getDimension());
		CMyMatrix j_von_x = jacobi(x, funktion);
		CMyVektor delta_x = j_von_x.invers() * (-1 * f_von_x);

		if (f_von_x.get_length() < 1e-5)
		{
			cout << endl << "Ende wegen ||f(x)||<1e-5 bei " << endl
				<< "\tx = " << x << endl
				<< "\tf(x) = " << funktion(x) << endl
				<< "\t||f(x)|| = " << funktion(x).get_length() << endl;
			return;
		}

		cout << endl << "Schritt " << schritte << ":" << endl
			<< "\tx = " << x << endl
			<< "\tf(x) = " << f_von_x << endl
			<< "\tf'(x) = " << j_von_x
			<< "(f'(x))^(-1)) = " << j_von_x.invers()
			<< "dx = " << delta_x << endl
			<< "\t||f(x)|| = " << f_von_x.get_length() << endl;

		x = x + delta_x;
		schritte++;
	}
	cout << endl << "Ende wegen Schrittanzahl = 50 bei" << endl
		<< "\tx = " << x << endl
		<< "\tf(x) = " << funktion(x) << endl
		<< "\t||f(x)|| = " << funktion(x).get_length() << endl;
}