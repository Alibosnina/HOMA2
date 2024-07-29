#include "CZufall.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>

CZufall::CZufall() {}
CZufall::~CZufall() {}

int CZufall::wert(int a, int b) {
	return (rand() % (b-a+1)) + a;
}

void CZufall::initialisiere(int s) {
	srand(s);
}

std::vector<int> CZufall::test(int a, int b, int N) {

	std::vector<int> haeufigkeiten(b-a+1,0);
	

	for (int i = 0; i < N; i++)
	{
		haeufigkeiten[wert(a,b)-3] ++ ;
	}
	return haeufigkeiten;
}

std::vector<int> CZufall::test_falsch(int a, int b, int N) {
	std::vector<int> haeufigkeiten(b-a+1, 0);
	for (int i = 0; i < N; i++)
	{
		initialisiere(time(NULL));
		haeufigkeiten[wert(a,b)-3] ++ ;
	}
	return haeufigkeiten;
}