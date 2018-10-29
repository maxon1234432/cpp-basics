#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double a, z1=0, z2=0;// значени€ которые нужно посчитать
	
	const float Pi = 3.1415926535;//константа ѕи
	cout << "Var 10 Suvorov\n";
	cout << "Vvedite ugol\n";
	cin >> a;
	z1 = sin((Pi / 2) + 3 * a) / (1 - sin(3 * a - Pi));
	
	
	z2 = 1 / tan(((5 / 4)*Pi) + ((3 / 2)*a));
	
	cout << "z1 = " << z1 << endl << "z2 = " << z2 << endl;
	return 0;

	
}