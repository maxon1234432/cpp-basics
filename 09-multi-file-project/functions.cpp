#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

void zadacha1(int Arr[20]) {
	cout << "1zadanie";
	cout << "\n";
	cout << "dan massiv\n";
	for (int i = 0; i < 20; i++) { cout << Arr[i] << " "; }
	cout << endl;
	int min = Arr[1];
	for (int i = 0; i < 20; i++)
	{
		if (abs(Arr[i]) < min)
		{
			min = abs(Arr[i]);
		}
	}
	cout << "minimalny po modulu = " << abs(min);
	cout << "\n";
}

void zadacha2(int Arr[20]) {
	cout << "2zadanie";
	cout << "\n";
	int k = 20;
	for (int i = 0; i < 20; i++)
	{
		if (Arr[i] == 0)
		{
			k = i;
			break;
		}
	}
	if (k == 20)
		cout << "net elementa ravnogo 0"; else {
		cout << "index elementa ravnogo 0=" << k;
		cout << "\n";
		//i = k;
		int summ = 0;
		for (int i = k; i < 20; i++)
		{
			summ = summ + Arr[i];
		}
		cout << "Summa el posle 1 el ravnogo 0=" << summ;
	}
	cout << "\n";
}

void zadacha3(int Arr[20]) {
	cout << "3 Zadanie";
	cout << "\n";
	cout << "bez sortirovki";
	cout << "\n";
	//	int i = 0;
	for (int j = 0; j < 20; j++) { printf("(%d)%d;", j + 1, Arr[j]); }

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			int cup;
			cup = Arr[i];
			Arr[i] = Arr[19 - i];
			Arr[19 - i] = cup;
		}
	}
	cout << "\n";
	cout << "OTSORTIROVANNY MASSIV";
	cout << "\n";
	for (int j = 0; j < 20; j++) { printf("(%d)%d;", j + 1, Arr[j]); }
	cout << "\n";
}