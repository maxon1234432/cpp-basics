#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a;
    cout << "Vvedite ugol alpha: ";
    cin >> a;

    double z1 = sin(M_PI_2 + 3.0*a) / (1.0 - sin(3.0*a - M_PI));
    double z2 = 1.0 / tan(5.0/4.0 * M_PI + 3.0/2.0 * a);

    cout << "\nz1 = " << z1 << "\nz2 = " << z2 << endl;

    return 0;
}