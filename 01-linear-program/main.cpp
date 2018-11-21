#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>



using namespace std;



int main()

{

	double a, z1, z2;

	cout << "Vvedite ugol alpha";

	cin >> a;

	z1 = sin(M_PI / 2 + 3 * a) / 1 - sin(3 * a - M_PI);

	z2 = 1 / tan(5 / 4 * M_PI + 3 / 2 * a);

	cout << "z1= "<< z1 << endl <<"Z2= " << z2;

	
	return 0;
}