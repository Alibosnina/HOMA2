#pragma once
#include <vector>

class CLotto
{
private:
	int n;//zahlen bereich
	int k;//k mal zahlen ziehen
	int s;//seed for randomizer
	std::vector<int> tippzettel;//fools chance
	//CZufall random;
public:
	CLotto(int eingabe_n, int eingabe_k, int eingabe_s);
	void tippzettel_setzen(std::vector<int> eingabe);
	std::vector<int> zahlenziehen();//k aus 0-n
	int lottospielen();//get random winner numbers and count matches with tippzettel
};

void spielerEINS(int r, int k, int n, int N, std::vector<int> tippzettel);
void spielerZWEI(int r, int k, int n, int N);
double typeeinsspieler(int r, int k, int n, int N);
double typezweispieler(int r, int k, int n, int N);
void montecarlo_lotto_giveinfo(int r, int k, int n);