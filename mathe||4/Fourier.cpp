#define _USE_MATH_DEFINES
#include <math.h>
#include "Fourier.h"
using namespace std;


std::vector<CKomplex> fourier_transformation(std::vector<CKomplex> daten, bool entr) 
//wandelt ein Signal von seinem ursprünglichen Bereich (oft Zeit oder Raum) in den Frequenzbereich um
{
    std::vector<CKomplex> result;
    result.resize(daten.size());
    int N = daten.size();
    for (int n = 0; n < N; n++) {
        CKomplex aktuell;
        for (int k = 0; k < N; k++) {
            CKomplex e;
            if(entr == true ) {e = CKomplex(-1 * (2 * M_PI * k * n) / N); } // 1/sqrt(N) * ∑ von k=0 bis N−1 xk * e^(−j (2π/N )*k*n)
            else {e = CKomplex(1 * (2 * M_PI * k * n) / N);} // 1/sqrt(N) * ∑ von k=0 bis N−1 xk * e^(j (2π/N )*k*n)
            aktuell = aktuell + daten.at(k) * e ; 
        }
        aktuell = (1 / sqrt(N)) * aktuell; 
        result.at(n) = aktuell; 
    }
    return result;
}


//wandelt das Signal aus dem Frequenzbereich in seinen ursprünglichen Bereich zurück
/*std::vector<CKomplex> fourier_ruecktrantransformation(std::vector<CKomplex> daten) {
    std::vector<CKomplex> result;
    result.resize(daten.size());
    int N = daten.size();
    for (int n = 0; n < N; n++) {
        CKomplex aktuell;
        for (int k = 0; k < N; k++) {
			// Exponential term
            CKomplex e(1 * (2 * M_PI * k * n) / N); // 1/sqrt(N) * ∑ von k=0 bis N−1 xk * e^(j (2π/N )*k*n)
            aktuell = aktuell + daten.at(k) * e; 
        }
        aktuell = (1 / sqrt(N)) * aktuell; 
        result.at(n) = aktuell; 
    }
    return result;
}*/





