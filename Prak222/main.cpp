#include <iostream>
#include "CMyMatrix.h"
#include "CMyVektor.h"
using namespace std;

CMyVektor f(CMyVektor xvec)
{
	CMyVektor z(2);
	double x1 = xvec.getKomp(0),
		   x2 = xvec.getKomp(1);
		
	z.setKomp(pow(x1,2) * x2 + x1, 0);
	z.setKomp(pow(x2,2) + (2*x2), 1);
	return z;
}

CMyVektor g(CMyVektor xvec)
{
	CMyVektor z(2);
	double x = xvec.getKomp(0),
		   y = xvec.getKomp(1);

	z.setKomp(pow(x,2) * y + x -1, 0);
	z.setKomp(pow(y,2) + 2*y -2, 1);
	return z;
}

int main()
{
	CMyVektor test(2);
	test.setKomp(1, 0);
	test.setKomp(2, 1);
	cout << "Jacobi-Matrix zu: ";
	cout << jacobi(test, *f) << endl;
	
	CMyVektor startwert(2);
	startwert.setKomp(-1, 0);
	startwert.setKomp(0, 1);

	newtonverfahren(startwert, *g);

	return 0;
}