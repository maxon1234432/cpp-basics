#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;


int main()
{
	cout << "1zadanie";
	cout << "\n";
	cout << "dan massiv\n";
	int Arr[20], Brr[10], Crr[20], min, k = 0;
	//Arr = new int[20]; 
	//Brr = new int[10];
	//Crr = new int[10];
	srand(time(NULL));
	int num;
	for (int i = 0; i < 20; i++)
	{
		num = rand() % 15 - 0;
		Arr[i] = num;
	}
	for (int i = 0; i < 20; i++) { cout << Arr[i] << " "; }
	cout << endl;
	min = Arr[1];
	for (int i = 0; i < 20; i++)
	{
		if (abs(Arr[i]) < min)
		{
			min = abs(Arr[i]);


		}

	}
	cout << "minimalny po modulu = " << abs(min);
	cout << "\n";
	//cout << " index 0 = " << k;
	cout << "2zadanie";
	cout << "\n";
	k = 20;
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
	cout << "3 Zadanie";
	cout << "\n";
	cout << "bez sortirovki";
	cout << "\n";
	//	int i = 0;
	for (int j = 0; j < 20; j++) {
		printf("(%d)%d;", j + 1, Arr[j]);
		//cout << Arr[j] + " ; ";
	}

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			int cup;
			cup = Arr[i];
			Arr[i] = Arr[19 - i];
			Arr[19 - i] = cup;
		}
	}

	cout << "\n";
	cout << "el c index";
	cout << "\n";
	//	int i = 0;
	for (int j = 0; j < 20; j++) {
		printf("(%d)%d;", j + 1, Arr[j]);
		//cout << Arr[j] + " ; "; 
	}


	cout << "\n";
	system("pause");
}