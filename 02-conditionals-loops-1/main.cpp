#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    const double kEps = 1e-15;

    double a, b, c, xn, xk, dx;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter xk >= xn: ";
    cin >> xk;
    cout << "Enter dx > 0: ";
    cin >> dx;

    if (dx <= 0 || xk < xn)
    {
        cout << "\nError input data.\n";
        return 1;
    }

    cout << endl << string(37, '-') << endl;
    cout << "|" << setw(9) << "x" << setw(9);
    cout << "|" << setw(9) << "F" << setw(10) << "|\n";
    cout << string(37, '-') << endl;

    cout << fixed;
    cout.precision(3);

    for (double x = xn; x <= xk; x += dx)
    {
        cout << "|" << setw(11) << x << setw(7) << "|";

        double f;
        if ((x < 3) && abs(b) >= kEps)
        {
            f = a * x * x - b * x + c;
        }
        else if ((x > 3) && abs(b) < kEps)
        {
            if (abs(x - c) >= kEps)
            {
                f = (x - a) / (x - c);
            }
            else
            {
                cout << "  division by 0  |\n";
                continue;
            }
        }
        else
        {
            if (abs(c) >= kEps)
            {
                f = x / c;
            }
            else
            {
                cout << "  division by 0  |\n";
                continue;
            }
        }

        int ac = static_cast<int>(a);
        int bc = static_cast<int>(b);
        int cc = static_cast<int>(c);
        if (~(ac | bc) & (ac ^ cc))
            cout << setw(11) << f << setw(8);
        else
            cout << setw(9) << static_cast<int>(f) << setw(10);
        cout << "|\n";
    }
    cout << string(37, '-') << endl;

    return 0;
}