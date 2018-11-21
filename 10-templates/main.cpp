#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define WEITH 10

using namespace std;

template <class type>
void input(type(&matrix)[WEITH][WEITH], ifstream &fin) {
	for (int j = 0; j < WEITH; j++)
		for (int i = 0; i < WEITH; i++)
			fin >> matrix[i][j];
}

template <class type>
void searchLocMin(type(matrix)[WEITH][WEITH]) {
	int numberOfMin = 0; // kol-vo lok minimumov
	for (int i = 0; i < WEITH; i++)
	{
		for (int j = 0; j < WEITH; j++)
		{
			bool min = true; 
			if (i != 0)
				if (matrix[i - 1][j] <= matrix[i][j]) // esly sosed menshe to ne lok min
					min = false;
			if (i != WEITH - 1)
				if (matrix[i + 1][j] <= matrix[i][j]) // analogy
					min = false;
			if (j != 0)
				if (matrix[i][j - 1] <= matrix[i][j])
					min = false;
			if (j != WEITH - 1)
				if (matrix[i][j + 1] <= matrix[i][j])
					min = false;
			if (min == true)
				numberOfMin++; // schetchik loc min +1
		}
	}
	std::cout << "Kol-vo lokalnih minimumov = " << numberOfMin << endl; // vyvod
}

template <class type>
void summGlavDiag(type(matrix)[WEITH][WEITH]) {
	int sum = 0; // summa
	for (int j = 0; j < WEITH; j++)
	{
		for (int i = j + 1; i < WEITH; i++) // prochod vyshe gl diiag
		{
			sum += matrix[i][j]; // summa + element matr
		}
	}
	std::cout << "summa = " << sum << endl; // vyvod
}

int main() {
	ifstream fin("int.txt");
	if (!fin.is_open()) {
		cout << "can't found int file" << endl;
	}
	else {
		int matrix[WEITH][WEITH];
		input(matrix, fin);
		cout << "in int file :" << endl;
		searchLocMin(matrix);
		summGlavDiag(matrix);
	}
	fin.close();
	ifstream fin2("double.txt");
	if (!fin2.is_open()) {
		cout << "can't found double file" << endl;
	}
	else {
		double matrix[WEITH][WEITH];
		input(matrix, fin2);
		cout << "in double file :" << endl;
		searchLocMin(matrix);
		summGlavDiag(matrix);
	}
	fin2.close();
	ifstream fin3("float.txt");
	if (!fin3.is_open()) {
		cout << "can't found float file" << endl;
	}
	else {
		float matrix[WEITH][WEITH], b[WEITH][WEITH];
		input(matrix, fin3);
		cout << "in float file :" << endl;
		searchLocMin(matrix);
		summGlavDiag(matrix);
	}
	fin3.close();
	return 0;
}