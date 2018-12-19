#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int** ReadMatrix(string file_name, int size);
void PrintMatrix(int** matrix, int size);
bool IsLessThanNeighbors(int** matrix, int size, int i, int j);
int CountLocalMinima(int** matrix, int size);
int SumAbsElemAboveDiagonal(int** matrix, int size);

int main()
{
    int size = 10;
    int** matrix = ReadMatrix("matrix.txt", size);
    if (!matrix) return 1;

    cout << "Matrix:\n";
    PrintMatrix(matrix, size);
    cout << endl;

    cout << "\nNumber of local minima: " << CountLocalMinima(matrix, size) << endl;
    cout << "\nSum of absolute values of elements above the main diagonal: ";
    cout << SumAbsElemAboveDiagonal(matrix, size) << endl;

    for (int i = 0; i < size; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}

int** ReadMatrix(string file_name, int size)
{
    ifstream fin(file_name);
    if (!fin.is_open())
    {
        cout << "\nCan't open file " << file_name << "!\n";
        return nullptr;
    }

    int** matrix = new int*[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++)
            fin >> matrix[i][j];
    }
    fin.close();
    return matrix;
}

void PrintMatrix(int** matrix, int size)
{
    cout << string(5 * size + 1, '-');
    for (int i = 0; i < size; i++)
    {
        cout << "\n|";
        for (int j = 0; j < size; j++)
            cout << setw(3) << matrix[i][j] << setw(2) << "|";
    }
    cout << endl << string(5 * size + 1, '-');
}

bool IsLessThanNeighbors(int** matrix, int size, int i, int j)
{
    for (int k = -1; k <= 1; k++)
        for (int l = -1; l <= 1; l++)
            if (((i + k) >= 0) && ((i + k) < size) &&
                ((j + l) >= 0) && ((j + l) < size) && ((k != 0) || (l != 0)))
                if (matrix[i][j] >= matrix[i + k][j + l])
                    return 0;
    return 1;
}

int CountLocalMinima(int** matrix, int size)
{
    int num_local_minima = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (IsLessThanNeighbors(matrix, size, i, j))
                num_local_minima++;
    return num_local_minima;
}

int SumAbsElemAboveDiagonal(int** matrix, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            sum += abs(matrix[i][j]);
    return sum;
}