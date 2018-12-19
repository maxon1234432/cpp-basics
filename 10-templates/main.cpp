#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

template <class T>
T** ReadMatrix(string file_name, int size);

template <class T>
void PrintMatrix(T** matrix, int size);

template <class T>
bool IsLessThanNeighbors(T** matrix, int size, int i, int j);

template <class T>
int CountLocalMinima(T** matrix, int size);

template <class T>
T SumAbsElemAboveDiagonal(T** matrix, int size);

template <class T>
int Execute(string file_name);

int main()
{
    string select;
selection:
    cout << "Select the data type (0-integer, 1-double, 2-float): ";
    cin >> select;
    if (select == "0")
    {
        Execute<int>("int.txt");
    }
    else if (select == "1")
    {
        Execute<double>("double.txt");
    }
    else if (select == "2")
    {
        Execute<float>("float.txt");
    }
    else
    {
        cout << "Error input! (Only 0, 1 or 2).\n\n";
        goto selection;
    }

    return 0;
}

template <class T>
int Execute(string file_name)
{
    int size = 10;
    T** matrix = ReadMatrix<T>(file_name, size);
    if (!matrix) return 1;

    cout << "\nMatrix:\n";
    PrintMatrix(matrix, size);
    cout << endl;

    cout << "\nNumber of local minima: " << CountLocalMinima(matrix, size) << endl;
    cout << "\nSum of absolute values of elements above the main diagonal: ";
    cout << SumAbsElemAboveDiagonal(matrix, size) << endl;

    for (int i = 0; i < size; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}

template <class T>
T** ReadMatrix(string file_name, int size)
{
    ifstream fin(file_name);
    if (!fin.is_open())
    {
        cout << "\nCan't open file " << file_name << "!\n";
        return nullptr;
    }

    T** matrix = new T*[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new T[size];
        for (int j = 0; j < size; j++)
            fin >> matrix[i][j];
    }
    fin.close();
    return matrix;
}

template <class T>
void PrintMatrix(T** matrix, int size)
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

template <class T>
bool IsLessThanNeighbors(T** matrix, int size, int i, int j)
{
    for (int k = -1; k <= 1; k++)
        for (int l = -1; l <= 1; l++)
            if (((i + k) >= 0) && ((i + k) < size) &&
                ((j + l) >= 0) && ((j + l) < size) && ((k != 0) || (l != 0)))
                if (matrix[i][j] >= matrix[i + k][j + l])
                    return 0;
    return 1;
}

template <class T>
int CountLocalMinima(T** matrix, int size)
{
    int num_local_minima = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (IsLessThanNeighbors(matrix, size, i, j))
                num_local_minima++;
    return num_local_minima;
}

template <class T>
T SumAbsElemAboveDiagonal(T** matrix, int size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            sum += abs(matrix[i][j]);
    return sum;
}