#pragma once
#include <vector>

class CKomplex
{
	private:
		double imaginaerteil = 0;
		double realteil = 0;
		double phi = 0;
	public:
		CKomplex(double a,double b);
		CKomplex(double phi);
		CKomplex();
		~CKomplex();

		double real();
		double imaginaer();
		double abs();
		friend CKomplex operator+ (CKomplex a, CKomplex b);
		friend CKomplex operator* (CKomplex a, CKomplex b);
		friend CKomplex operator* (double a, CKomplex b);
};

std::vector<CKomplex> werte_einlesen(const char* dateiname);
void werte_ausgeben(const char* dateiname, std::vector<CKomplex> werte, double epsilon = -1.0);

std::vector<CKomplex> fourier_transformation(std::vector<CKomplex> daten,bool entr);
//std::vector<CKomplex> fourier_ruecktrantransformation(std::vector<CKomplex> daten);

double abweichung(std::vector<CKomplex> a, std::vector<CKomplex> b);