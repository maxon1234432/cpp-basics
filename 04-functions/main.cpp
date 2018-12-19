#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

void PrintTableHead();
double ComputeSeries(double x, double eps, int &n, const int kMaxIter);
void PrintTableRow(double x, double func, int n, const int kMaxIter);

int main()
{
    const int kMaxIter = 1000000;

    double xn, xk, dx, eps;
    cout << "|x| < 1\n";
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter xk >= xn: ";
    cin >> xk;
    cout << "Enter dx > 0: ";
    cin >> dx;
    cout << "Enter eps > 0: ";
    cin >> eps;

    if (dx <= 0 || xk < xn || eps <= 0 || abs(xn) >= 1 || abs(xk) >= 1)
    {
        cout << "\nError input data.\n";
        return 1;
    }

    cout << fixed;

    PrintTableHead();
    for (double x = xn; x <= xk; x += dx)
    {
        int n;
        double func = ComputeSeries(x, eps, n, kMaxIter);
        PrintTableRow(x, func, n, kMaxIter);
    }
    cout << string(66, '-') << endl;

    return 0;
}

void PrintTableHead()
{
    cout << endl << string(66, '-') << endl;
    cout << "|      x      ";
    cout << "|  arth(x) (mine)  ";
    cout << "|  arth(x) (cmath) ";
    cout << "| iterations |\n";
    cout << string(66, '-') << endl;
}

double ComputeSeries(double x, double eps, int &n, const int kMaxIter)
{
    double nth_term = x;
    double func = nth_term;
    n = 1;
    while (abs(nth_term) > eps)
    {
        nth_term = pow(x, (2 * n + 1)) / (2 * n + 1);
        func += nth_term;
        n++;
        if (n > kMaxIter) break;
    }
    return func;
}

void PrintTableRow(double x, double func, int n, const int kMaxIter)
{
    cout << "|" << setw(11) << x << setw(3) << "|" << setw(13);
    if (n <= kMaxIter)
        cout << func << setw(6) << "|";
    else
        cout << "  limit exceeded  |";
    cout << setw(13) << atanh(x) << setw(6) << "|";
    cout << setw(7) << n << setw(7) << "|\n";
}