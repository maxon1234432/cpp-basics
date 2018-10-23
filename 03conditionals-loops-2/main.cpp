

#include <iostream>
#include <conio.h>
#include <locale.h>
#include <math.h>

using namespace std;

int main()
{
	double x1 = 0.1, x2 = 0.5, dx = 0.05, eps = 0.0001, sum, nj = 0;
	int k;
	for (double i = x1; i < x2; i = i + dx)
	{
		sum = 0;
		k = 0;
		nj++;
		for (double n = 0; eps < fabs(pow(i, (2 * n + 1)) / (2 * n + 1)); n++)
		{
			k++;
			sum += pow(i, (2 * n + 1)) / (2 * n + 1);//(x/1)+(x3/3)
		}
		printf("n =%3.0f\tx = %3.4f\tsum = %3.4f\tk = %3.0d\n", nj, i, sum, k);
	}
	system("PAUSE");
	return 0;
}