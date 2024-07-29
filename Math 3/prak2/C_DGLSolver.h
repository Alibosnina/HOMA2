#pragma once
#include "CMyVektor.h"

class C_DGLSolver
{
public:
	C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x));
	C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVektor y, double x));

	void euler(double xstart, double xend, int anzahlSchritte, CMyVektor y_start,bool abweichung);
	void heun(double xstart, double xend, int anzahlSchritte, CMyVektor y_start,bool abweichung);
private:
	bool hohereOrdnung = false; //privates Attribut, um zu pr�fen, ob ein DGL-System oder eine DGL h�herer Ordnung behandelt werden soll
	CMyVektor (*f_DGL_System)(CMyVektor y, double x); //Funktionspointer, die die rechte Seite eines DGL-Systems repr�sentiert
	double (*f_DGL_nterOrdnung)(CMyVektor y, double x); //Funktionspointer, die eine DGL h�herer Ordnung repr�sentiert

	CMyVektor ableitungen(CMyVektor y, double x);
};