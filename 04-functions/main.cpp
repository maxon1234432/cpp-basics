#include <iostream>
#include <math.h>

using namespace std;

void func(double x1, double x2, double dx, double eps);
double summa(double i, double n);
void vivod(double nj, double i, double sum, int k);

void main()
{
	double x1 = 0.1, x2 = 0.5, dx = 0.05, eps = 0.0001;
	func(x1, x2, dx, eps);
}

void func(double x1, double x2, double dx, double eps) {
	int k;
	double sum, nj = 0;
	for (double i = x1; i < x2; i = i + dx)
	{
		sum = 0;
		k = 0;
		nj++;
		for (double n = 0; eps < fabs(pow(i, (2 * n + 1)) / (2 * n + 1)); n++)
		{
			k++;
			sum += summa(i, n);
		}
		vivod(nj, i, sum, k);
	}
	
}
double summa(double i, double n) {
	return pow(i, (2 * n + 1)) / (2 * n + 1);
}
void vivod(double nj, double i, double sum, int k) {
	printf("n =%3.0f\tx = %3.4f\tsum = %3.4f\tk = %3.0d\n", nj, i, sum, k);
}