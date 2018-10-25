#include <iostream>
#include <ctime>
#include <cmath>

int main()
{
	int const WEITH = 10; // размерность матрицы
	int matrix[WEITH][WEITH]; // создаем Матриц
	srand(time(NULL)); // генератор случайных чисел
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = 0; j < WEITH; j++)
		{
			matrix[i][j] = rand() % WEITH - 0; // заполняем матрицу случайными значениями
		}
	}
	std::cout << "\n\n";
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = 0; j < WEITH; j++)
		{
			printf("%3d", matrix[i][j]); // используя форматированный вывод для красивого вывода матрицы
		}
		std::cout << "\n\n";
	}
	int numberOfMin = 0; // переменная определяющая количество локальных минимумов
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = 0; j < WEITH; j++)
		{
			bool min = true; // изначально надеемся что она таковая
			if (i != 0)
				if (matrix[i - 1][j] <= matrix[i][j]) // если сосед меньше то переменная не локальный минимум
					min = false;
			if (i != WEITH - 1)
				if (matrix[i + 1][j] <= matrix[i][j]) // дальше по аналогии
					min = false;
			if (j != 0)
				if (matrix[i][j - 1] <= matrix[i][j])
					min = false;
			if (j != WEITH - 1)
				if (matrix[i][j + 1] <= matrix[i][j])
					min = false;
			if (min == true)
				numberOfMin++; // увеличиваем счётчик локальных минимумов
		}
	}
	std::cout << "\n" << "Kol-vo lokalnih minimumov = " << numberOfMin; // вывод
	int sum = 0; // переменная определяющая сумму
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = i + 1; j < WEITH; j++) // проход выше главной диагонали
		{
			sum += matrix[i][j]; // увеличиваем сумму
		}
	}
	std::cout << "\n" << "summa = " << sum; // вывод
}
