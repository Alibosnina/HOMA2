#include <iostream>
#include "CZufall.h"
#include "CLotto.h"
#include <iomanip>
using namespace std;

int main()
{
	cout << "Praktikum 5  " << endl << endl;
	int eingabe, g;

	while (true) {
		cout << "Menu :" << endl
			<< "1) Zufall" << endl
			<< "2) Lotto" << endl
			<< "3) Montecarlo_lotto" << endl
            << "4) Program beenden" << endl
			<< "?> ";
		cin >> eingabe;
		if (eingabe == 1) 
		{
			cout << "Welche Werte mochten Sie nutzen ?" << endl
				<< "1) mit gleichem Wert fur s aufrufen" << endl
				<< "2) mit mit verschiedenen Werten fur s aufrufen," << endl
				<< "3) immer gleiche Werte (mit time(NULL))" << endl
				<< "4) immer nur eine Zahl aus dem Bereich" << endl
				<< "?>";
			cin.ignore();
			cin >> g;
			if(g==1) 
			{
				CZufall aufgabe1;
				int s = 0;
				aufgabe1.initialisiere(s);
				vector<int> anzahlen1 = aufgabe1.test(3, 7, 10000);
					for (int i = 0; i <= 4; i++)
						cout << "Hauefigkeit von " << i+3 << " " << anzahlen1.at(i) << endl;
						cout << "----" << endl;
				aufgabe1.initialisiere(s);
				vector<int> anzahlen2 = aufgabe1.test(3, 7, 10000);
					for (int i = 0; i <= 4; i++)
						cout << "Hauefigkeit von " << i + 3 << " " << anzahlen2.at(i) << endl;
						cout << "----" << endl;
				aufgabe1.initialisiere(s);
				vector<int> anzahlen3 = aufgabe1.test(3, 7, 10000);
					for (int i = 0; i <= 4; i++)
						cout << "Hauefigkeit von " << i + 3<< " " << anzahlen3.at(i) << endl;
						cout << "----" << endl;
				aufgabe1.initialisiere(s);
				vector<int> anzahlen4 = aufgabe1.test(3, 7, 10000);
					for (int i = 0; i <= 4; i++)
						cout << "Hauefigkeit von " << i +3 << " " << anzahlen4.at(i) << endl;
			}
			if(g==2)
			{
				CZufall aufgabe1;
				cout << "s = 0" << endl;
				aufgabe1.initialisiere(0);
				vector<int> anzahlen1 = aufgabe1.test(3, 7, 10000);
					for (int i = 3; i <= 7; i++)
						cout << "Hauefigkeit von " << i << " " << anzahlen1.at(i) << endl;
						cout << "----" << endl;

				cout << "s = 1" << endl;
				aufgabe1.initialisiere(1);
				vector<int> anzahlen2 = aufgabe1.test(3, 7, 10000);
					for (int i = 3; i <= 7; i++)
						cout << "Hauefigkeit von " << i << " " << anzahlen2.at(i) << endl;
						cout << "----" << endl;

				cout << "s = 2" << endl;
				aufgabe1.initialisiere(2);
				vector<int> anzahlen3 = aufgabe1.test(3, 7, 10000);
					for (int i = 3; i <= 7; i++)
						cout << "Hauefigkeit von " << i << " " << anzahlen3.at(i) << endl;
						cout << "----" << endl;

				cout << "s = 3" << endl;
				aufgabe1.initialisiere(3);
				vector<int> anzahlen4 = aufgabe1.test(3, 7, 10000);
					for (int i = 3; i <= 7; i++)
						cout << "Hauefigkeit von " << i << " " << anzahlen4.at(i) << endl;
			}
			if(g==3)
			{
				CZufall aufgabe1;
					int s = time(NULL);
					aufgabe1.initialisiere(s);
					vector<int> anzahlen1 = aufgabe1.test(3, 7, 10000);
					for (int i = 3; i <= 7; i++)
						cout << "Hauefigkeit von " << i << " " << anzahlen1.at(i) << endl;
					cout << "----" << endl;
					aufgabe1.initialisiere(s);
					vector<int> anzahlen2 = aufgabe1.test(3, 7, 10000);
					for (int i = 3; i <= 7; i++)
						cout << "Hauefigkeit von " << i << " " << anzahlen2.at(i) << endl;
					cout << "----" << endl;
					aufgabe1.initialisiere(s);
					vector<int> anzahlen3 = aufgabe1.test(3, 7, 10000);
					for (int i = 3; i <= 7; i++)
						cout << "Hauefigkeit von " << i << " " << anzahlen3.at(i) << endl;
					cout << "----" << endl;
					aufgabe1.initialisiere(s);
					vector<int> anzahlen4 = aufgabe1.test(3, 7, 10000);
					for (int i = 3; i <= 7; i++)
						cout << "Hauefigkeit von " << i << " " << anzahlen4.at(i) << endl;
			}
			if(g==4)
			{
				CZufall aufgabe1;
				vector<int> anzahlen1 = aufgabe1.test_falsch(3, 7, 10000);
					for (int i = 3; i <= 7; i++)
						cout << "Hauefigkeit von " << i << " " << anzahlen1.at(i) << endl;
			}
		}
		else if (eingabe == 2) 
		{
			vector<int> testtz = { 4,8,11,19,25,1,10,3 };
			spielerEINS(2, 8, 30, 10000,testtz);
			spielerZWEI(2, 8, 30, 10000);
		}
        else if (eingabe == 3) 
		{
			montecarlo_lotto_giveinfo(2, 8, 30);
            break;
		}
		else if (eingabe == 4) 
		{
		break;
		cout << endl << endl;
		}

	}

	//Aufgabe 1 a)
	/*CZufall aufgabe1;
	int s = 0;
	aufgabe1.initialisiere(s);
	vector<int> anzahlen = aufgabe1.test(3, 7, 10000);
	for (int i = 3; i <= 7; i++)
	{
		cout << "Hauefigkeit von " << i << " " << anzahlen.at(i) << endl;
 	}*/

	return 0;
}