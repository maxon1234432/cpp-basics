#include <iostream>
#include <conio.h>
#include <locale.h>
#include <math.h>
using namespace std;

int main()
{
	double z1, z2;
	int a;
	float Pi = 3.1415926535;
	cout << "Var 10 Suvorov\n";
	cout << "Vvedite ugol\n";
	cin >> a;
	z1 = sin((Pi / 2) + 3 * a) / (1 - sin(3 * a - Pi));
	cout << "z1= " << z1;
	cout << "\n";
	z2 = 1 / tan(((5 / 4)*Pi) + ((3 / 2)*a));
	cout << "z2= " << z2;
	cout << "\n";

	system("PAUSE");
}