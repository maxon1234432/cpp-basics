#include <iostream>
#include <ctime>
#include <cmath>

int main()
{
	int const WEITH = 10; // ����������� �������
	int matrix[WEITH][WEITH]; // ������� ������
	srand(time(NULL)); // ��������� ��������� �����
	std::cout << "MATRICA A 10X10";
	std::cout << "\n";
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = 0; j < WEITH; j++)
		{
			matrix[i][j] = rand() % WEITH - 0; // ��������� ������� ���������� ����������
		}
	}
	std::cout << "\n\n";
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = 0; j < WEITH; j++)
		{
			printf("%3d", matrix[i][j]); // ��������� ��������������� ����� ��� ��������� ������ �������
		}
		std::cout << "\n\n";
	}
	int numberOfMin = 0; // ���������� ������������ ���������� ��������� ���������
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = 0; j < WEITH; j++)
		{
			bool min = true; // ���������� �������� ��� ��� �������
			if (i != 0)
				if (matrix[i - 1][j] <= matrix[i][j]) // ���� ����� ������ �� ���������� �� ��������� �������
					min = false;
			if (i != WEITH - 1)
				if (matrix[i + 1][j] <= matrix[i][j]) // ������ �� ��������
					min = false;
			if (j != 0)
				if (matrix[i][j - 1] <= matrix[i][j])
					min = false;
			if (j != WEITH - 1)
				if (matrix[i][j + 1] <= matrix[i][j])
					min = false;
			if (min == true)
				numberOfMin++; // ����������� ������� ��������� ���������
		}
	}
	std::cout << "\n" << "Kol-vo lokalnih minimumov = " << numberOfMin; // �����
	int sum = 0; // ���������� ������������ �����
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = i + 1; j < WEITH; j++) // ������ ���� ������� ���������
		{
			sum += matrix[i][j]; // ����������� �����
		}
	}
	std::cout << "\n" << "summa el vyshe glavnoi diagonali = " << sum; // �����
	system("PAUSE");
}
