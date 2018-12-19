#include <iostream>

using namespace std;

void PrintArray(int* arr, const int kArraySize);
int FindAbsMin(int* arr, const int kArraySize);
int SumAbsElem(int* arr, const int kArraySize, int begin);
int FindFirstZero(int* arr, const int kArraySize);
void SortArray(int* arr, const int kArraySize);

int main()
{
    const int kArraySize = 10;
    int arr[kArraySize] = { 5, 1, -2, 0, -4, 5, 0, -7, 8, 4 };

    cout << "Initial array:\n";
    PrintArray(arr, kArraySize);
    cout << endl;

    cout << "\nAbsolute minimum element of array = ";
    cout << FindAbsMin(arr, kArraySize) << endl;

    cout << "\nSum of absolute values of array after first zero = ";
    int first_zero = FindFirstZero(arr, kArraySize);
    if (first_zero != -1)
        cout << SumAbsElem(arr, kArraySize, first_zero + 1) << endl;
    else
        cout << "\nNo zero elements in array.\n";

    SortArray(arr, kArraySize);
    cout << "\nSorted array:\n";
    PrintArray(arr, kArraySize);
    cout << endl;

    return 0;
}

void PrintArray(int* arr, const int kArraySize)
{
    cout << "[";
    for (int i = 0; i < kArraySize; i++)
        cout << arr[i] << ((i < kArraySize - 1) ? (", ") : ("]"));
}

int FindAbsMin(int* arr, const int kArraySize)
{
    int abs_min = arr[0];
    for (int i = 1; i < kArraySize; i++)
        if (abs(arr[i]) < abs(abs_min))
            abs_min = arr[i];
    return abs_min;
}

int FindFirstZero(int* arr, const int kArraySize)
{
    for (int i = 0; i < kArraySize; i++)
        if (arr[i] == 0)
            return i;
    return -1;
}

int SumAbsElem(int* arr, const int kArraySize, int begin)
{
    int sum = 0;
    for (int i = begin; i < kArraySize; i++)
        sum += abs(arr[i]);
    return sum;
}

void SortArray(int* arr, const int kArraySize)
{
    int index = 0;
    int* tmp_arr = new int[kArraySize];

    for (int i = 1; i < kArraySize; i += 2)
        tmp_arr[index++] = arr[i];
    for (int i = 0; i < kArraySize; i += 2)
        tmp_arr[index++] = arr[i];

    for (int i = 0; i < kArraySize; i++)
        arr[i] = tmp_arr[i];

    delete[] tmp_arr;
}