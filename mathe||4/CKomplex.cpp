#define _USE_MATH_DEFINES
#include "CKomplex.h"
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;


CKomplex::CKomplex(){}


CKomplex::~CKomplex() {}


CKomplex::CKomplex(double a, double b) {
    realteil = a;
    imaginaerteil = b;
}


CKomplex::CKomplex(double phi) {
    this->realteil = cos(phi);  
    this->imaginaerteil = sin(phi);  
    this->phi = phi;
}


double CKomplex::real() {
    return realteil;
}


double CKomplex::imaginaer() {
    return imaginaerteil;
}


CKomplex operator+(CKomplex a, CKomplex b) {
    CKomplex result(a.realteil + b.realteil, a.imaginaerteil + b.imaginaerteil); 
    return result;
}


CKomplex operator*(CKomplex a, CKomplex b) {
    CKomplex result((a.realteil * b.realteil) - (a.imaginaerteil * b.imaginaerteil), 
                    (a.realteil * b.imaginaerteil) + (b.realteil * a.imaginaerteil)); 
    return result;
}


CKomplex operator*(double a, CKomplex b) 
{
    CKomplex result(a * b.realteil, a * b.imaginaerteil);
    return result;
}


double abweichung(std::vector<CKomplex> a, std::vector<CKomplex> b) {
    double result = 0.0, tmp = 0.0;
    for (int i = 0; i < (int)a.size(); i++) {
        tmp = (a.at(i) + ((-1) * b.at(i))).abs(); 
        if (tmp > result) {
            result = tmp;
        }
    }
    return result; 
}


double CKomplex::abs() 
{
    return sqrt((this->realteil * this->realteil) + (this->imaginaerteil * this->imaginaerteil));
}


std::vector<CKomplex> werte_einlesen(const char* dateiname) {
    int i, N, idx;
    double re, im;
    std::vector<CKomplex> werte;
    std::ifstream fp;
    fp.open(dateiname); 
    fp >> N; // Read the number of complex numbers
    werte.resize(N); // Resize vector to hold N elements
    CKomplex null(0, 0);
    for (i = 0; i < N; i++)
        werte[i] = null; 
    while (!fp.eof()) {
        fp >> idx >> re >> im; // Read index, real part, and imaginary part
        CKomplex a(re, im);
        werte[idx] = a; 
    }
    fp.close(); 
    return werte; 
}


void werte_ausgeben(const char* dateiname, std::vector<CKomplex> werte, double epsilon) {
    int i;
    int N = werte.size();
    std::ofstream fp;
    fp.open(dateiname); 
    fp << N << std::endl; 
    fp.precision(10); 
    for (i = 0; i < N; i++)
        if (werte[i].abs() > epsilon)
            fp << i << "\t" << werte[i].real() << "\t" << werte[i].imaginaer() << std::endl; 
    fp.close(); 
}

