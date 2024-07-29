#pragma once
#include "CMyVektor.h"
class CMyMatrix
{
private:
	int row, cols;
	double** werte;

public:
	CMyMatrix(int, int);

	int getrows() const { return row; }

	int getcols() const { return cols; }

	double getnum(int row, int cols) const { return werte[row][cols]; }

	void setnum(double numb, int row, int cols) { werte[row][cols] = numb; }
	CMyMatrix invers();
};

CMyVektor operator*(CMyMatrix A, CMyVektor x);

std::ostream& operator<<(std::ostream& os, CMyMatrix x);

CMyMatrix jacobi(CMyVektor x, CMyVektor (*function)(CMyVektor x));

void newtonverfahren(CMyVektor x, CMyVektor (*funktion)(CMyVektor x));