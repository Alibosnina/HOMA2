#include "CLotto.h"
#include <time.h>
#include <iostream>
#include "CZufall.h"
#include <iomanip>
#include<cmath>



int CLotto::lottospielen()
{
	int winnercounter = 0;
	std::vector<int> luckynumbers = zahlenziehen();
	for (int i = 0; i < k; i++)//schleife fur tippzettel prufung
	{
		for (int j = 0; j < k; j++)//vergleichung zwischen ein element des tippzettels und alle luckynubmers
		{
			if (tippzettel[i] == luckynumbers[j])//es gibt keine doppelt Zahlen, deswegen keine Uberlappen 
			{
				winnercounter++;
			}
		}
	}
	return winnercounter;
}

std::vector<int> CLotto::zahlenziehen()//k mal zahlen ziehen
{
	
	std::vector<int> blatt;	
	CZufall random;
	int transporter = 0;
	blatt.clear();
	while (blatt.size() < k)
	{
		transporter = random.wert(0, n);//draw number
		bool init = false;
		for (int i = 0; i < blatt.size(); i++)//already drawn check loop
		{
			if (transporter == blatt[i]) //already drawn check
			{
				init = true;
			}
		}
		if (!init)//if new number save it 
			blatt.push_back(transporter);
		//we go to next iteration its gona be a new transporter intilisation with different random value
	}
	return blatt;
}


CLotto::CLotto(int eingabe_n, int eingabe_k, int eingabe_s)
{
	n = eingabe_n;
	k = eingabe_k;
	if (eingabe_s < 0)
		s = time(NULL);
	else
		s = eingabe_s;
	CZufall random;
	random.initialisiere(s);
	
}


void CLotto::tippzettel_setzen(std::vector<int> eingabe)
{
	if (eingabe.size() != k)
	{
		std::cout << "Falsch Tippzettel eingegeben!" << std::endl;
		system("pause");
	}
	tippzettel = eingabe;
}

void spielerEINS(int r, int k, int n, int N, std::vector<int> tippzettel)
{
	double wincount = 0;
	//tippzettel 4 8 15 16 23 42
	CLotto Lotto(n, k, -1);
	Lotto.tippzettel_setzen(tippzettel);
	for (int i = 0; i < N; i++)
	{
		if (Lotto.lottospielen() == r)
		{
			wincount++;
		}
	}
	double winprozent = wincount / N * 100;

	//infostelle
	std::cout << "**************************************" << std::endl;
	std::cout << "Simulation type : SPIELER 1\n";
	std::cout << "Win Count : " << wincount << std::endl;

	std::cout << N << " mal mit Tippzettel ( ";
	for (int i = 0; i < tippzettel.size(); i++)
	{
		std::cout << tippzettel[i] << ", ";
	}
	std::cout << ") simuliert.\n";
	std::cout << "Warhscheinlichkeit Wert in Prozent : " << std::setprecision(7) << winprozent << std::endl;
}

double typeeinsspieler(int r, int k, int n, int N)
{

	double wincount = 0;
	//tippzettel 4 8 15 16 23 42
	CLotto Lotto(n, k, -1);
	Lotto.tippzettel_setzen(Lotto.zahlenziehen());//einmal initilisieren : type 1

	for (int i = 0; i < N; i++)
	{
		if (Lotto.lottospielen() == r)
		{
			wincount++;
		}
	}
	double winprozent = wincount / N * 100;
	return winprozent;
}

double typezweispieler(int r, int k, int n, int N)
{
	double wincount = 0;
	CZufall random;
	CLotto Lotto(n, k, -1);

	for (int x = 0; x < N; x++)
	{
		Lotto.tippzettel_setzen(Lotto.zahlenziehen());

		if (Lotto.lottospielen() == r)
		{
			wincount++;
		}
	}
	double winprozent = wincount / N * 100;
	return winprozent;
}

void montecarlo_lotto_giveinfo(int r, int k, int n)
{
	std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "MONTE CARLO: \n";
	double type1[5];
	double type2[5];
	for (int i = 2; i < 7; i++)
	{
		std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;
		int N = pow(10, i);
		type1[i - 2] = typeeinsspieler(r, k, n, N);
		std::cout << "Type 1, N = " << N << " ->  " << type1[i - 2] << "%.\n";
		type2[i - 2] = typezweispieler(r, k, n, N);
		std::cout << "Type 2, N = " << N << " ->  " << type2[i - 2] << "%.\n";
		std::cout << "++++++++++++++++++++++++++++++++++++++++" << std::endl;

	}
	std::cout << "Unterschied zwischen Type1 und Type2 bei verschiedene N Werte\n";
	std::cout << "N = 100 -> " << abs(type1[0] - type2[0]) << std::endl;
	std::cout << "N = 1000 -> " << abs(type1[1] - type2[1]) << std::endl;
	std::cout << "N = 10000 -> " << abs(type1[2] - type2[2]) << std::endl;
	std::cout << "N = 100000 -> " << abs(type1[3] - type2[3]) << std::endl;
	std::cout << "N = 1000000 -> " << abs(type1[4] - type2[4]) << std::endl;
}


void spielerZWEI(int r, int k, int n, int N)
{
	double wincount = 0;
	CZufall random;
	CLotto Lotto(n, k, -1);

	for (int x = 0; x < N; x++)
	{
		Lotto.tippzettel_setzen(Lotto.zahlenziehen());

		if (Lotto.lottospielen() == r)
		{
			wincount++;
		}
	}

	//infostelle
	std::cout << "**************************************" << std::endl;
	std::cout << "Simulation type : SPIELER 2\n";
	std::cout << "Win Count : " << wincount << std::endl;
	std::cout << N << " mal simuliert.\n";
	std::cout << "Warhscheinlichkeit Wert in Prozent : " << wincount / N * 100 << std::endl;
}