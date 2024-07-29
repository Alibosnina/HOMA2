#ifndef __FOURIER_H__
#define __FOURIER_H__
#include <vector>
#include "CKomplex.h"

namespace Fourier
{
	extern std::vector<CKomplex> transformation(std::vector<CKomplex> daten,bool entr);
	//extern std::vector<CKomplex> zuruecktrantransformation(std::vector<CKomplex> daten);
}

#endif