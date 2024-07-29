#include <iostream>
#include <vector>
#include "CKomplex.h"
#include <string>
#include <fstream>
#include "Fourier.h"
using namespace std;

int main() {
	
    vector<CKomplex>original = werte_einlesen("Daten_original1.txt");
    vector<CKomplex> transformiert = fourier_transformation(original, true);

    werte_ausgeben("transformiert(-1).txt", transformiert);
    vector<CKomplex> ruecktransformiert1 = fourier_transformation(werte_einlesen("transformiert(-1).txt"), false);
    cout << "Maximale Abweichung bei Standard-Epsilon: ca. " << abweichung(original, ruecktransformiert1) << endl;
    werte_ausgeben("transformiert(0.001).txt", transformiert, 0.001);
    vector<CKomplex> ruecktransformiert0001 = fourier_transformation(werte_einlesen("transformiert(0.001).txt"), false);
    cout << "Maximale Abweichung bei epsilon=0.001: " << abweichung(original, ruecktransformiert0001) << endl;
    werte_ausgeben("transformiert(0.01).txt", transformiert, 0.01);
    vector<CKomplex> ruecktransformiert001 = fourier_transformation(werte_einlesen("transformiert(0.01).txt"), false);
    cout << "Maximale Abweichung bei epsilon=0.01: " << abweichung(original, ruecktransformiert001) << endl;
    werte_ausgeben("transformiert(0.1).txt", transformiert, 0.1);
    vector<CKomplex> ruecktransformiert01 = fourier_transformation(werte_einlesen("transformiert(0.1).txt"), false);
    cout << "Maximale Abweichung bei epsilon=0.1: " << abweichung(original, ruecktransformiert01) << endl;
    werte_ausgeben("transformiert(1).txt", transformiert, 1);
    vector<CKomplex> ruecktransformiert = fourier_transformation(werte_einlesen("transformiert(1).txt"), false);
    cout << "Maximale Abweichung bei epsilon=1: " << abweichung(original, ruecktransformiert) << endl;

	return 0;
}