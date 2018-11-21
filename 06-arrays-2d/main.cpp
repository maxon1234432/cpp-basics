#include <iostream>
#include <ctime>
#include <cmath>

int main()
{
	int const WEITH = 10; // razmer matr
	int matrix[WEITH][WEITH]; //sozdaem matr
	srand(time(NULL)); // generator slychainykh chisel
	std::cout << "MATRICA A 10X10";
	std::cout << "\n";
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = 0; j < WEITH; j++)
		{
			matrix[i][j] = rand() % WEITH - 0; // zapolnenie matr rand chislami
		}
	}
	std::cout << "\n\n";
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = 0; j < WEITH; j++)
		{
			printf("%3d", matrix[i][j]); // format vyvod dlya krasoty
		}
		std::cout << "\n\n";
	}
	int numberOfMin = 0; // schetchic localnykh minimumov
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = 0; j < WEITH; j++)
		{
			bool min = true; 
			if (i != 0)
				if (matrix[i - 1][j] <= matrix[i][j]) // esli coced < to ne loc min
					min = false;
			if (i != WEITH - 1)
				if (matrix[i + 1][j] <= matrix[i][j]) // analogichno
					min = false;
			if (j != 0)
				if (matrix[i][j - 1] <= matrix[i][j])
					min = false;
			if (j != WEITH - 1)
				if (matrix[i][j + 1] <= matrix[i][j])
					min = false;
			if (min == true)
				numberOfMin++; //uvelichivaem schetchik loc min
		}
	}
	std::cout << "\n" << "Kol-vo lokalnih minimumov = " << numberOfMin; // vyvod
	int sum = 0; // summma
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = i + 1; j < WEITH; j++) // prohod vyshe glavnoi diag
		{
			sum += matrix[i][j]; // scladyvaem
		}
	}
	std::cout << "\n" << "summa el vyshe glavnoi diagonali = " << sum; // vyvod
}
