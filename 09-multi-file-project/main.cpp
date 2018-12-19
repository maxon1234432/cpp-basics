#include "functions.h"

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