#include <iostream>
#include <string>
#include <cmath>
#include "CMyVektor.h"
using namespace std;

double f(CMyVektor x);
double g(CMyVektor x);

int main() {

	double(*funktiong)(CMyVektor);
	funktiong = g;
	double(*funktionf)(CMyVektor);
	funktionf = f;

	
			string func;
			cout << "Welche Funktion soll benutzt werden?: " << endl;
			cout << " f = sin(x * y) + sin(x) +cos(y)" << endl;
			cout << " g = -(2x1^2 - 2x1x2 + y^2 + z^2 - 2x - 4z)" << endl;
			cin >> func;
			if (func == "f") {
				CMyVektor test(2);
				test.setKomp(0.2, 0);
				test.setKomp(-2.1, 1);


				test.maximieren((*funktionf), test, 1.0);
			}
			else {
				CMyVektor test2(3);
				test2.setKomp(0, 0);
				test2.setKomp(0, 1);
				test2.setKomp(0, 2);


				test2.maximieren((*funktiong), test2, 0.1);
			}
	return 0;
}

double f(CMyVektor x) {
	return sin(x.getKomp(0) * x.getKomp(1)) + sin(x.getKomp(0)) + cos(x.getKomp(1)) ;

}
double g(CMyVektor x) {
	return -(2 * pow(x.getKomp(0), 2) - 2 * x.getKomp(0) * x.getKomp(1) + pow(x.getKomp(1), 2) + pow(x.getKomp(2), 2) - 2 * x.getKomp(0) - 4 * x.getKomp(2));
}