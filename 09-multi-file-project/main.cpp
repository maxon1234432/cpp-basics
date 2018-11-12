#include <iostream>
#include <ctime>
#include <cmath>
#include "functions.h"
using namespace std;


int main()
{
	int Arr[20];
	srand(time(NULL));
	int num;
	for (int i = 0; i < 20; i++)
	{
		num = rand() % 15 - 0;
		Arr[i] = num;
	}
	zadacha1(Arr);
	zadacha2(Arr);
	zadacha3(Arr);
}
