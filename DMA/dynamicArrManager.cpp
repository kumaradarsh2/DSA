#include <iostream>

using namespace std;

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void resizeArray(int** arr, int oldSize, int newSize) {
    // create a bigger array
    // int* brr = new int[newSize];

/*
    // doing the same thing using c-style
    int* brr = (int*) malloc(newSize * sizeof(int));

    // copy old values into bigger one
    for (int i = 0; i < newSize; ++i) {
        // if (i < oldSize) *(brr + i) = *(*arr + i);
        if (i < oldSize) brr[i] = (*arr)[i];
        else brr[i] = 0;
    }
*/

    // using calloc 
    int* brr = (int*) calloc(newSize, sizeof(int));

    for (int i = 0; i < oldSize; ++i) {
        brr[i] = (*arr)[i];
    }

    // delete[] *arr; // free the old one

    // c-style
    free(*arr);

    *arr = brr; // update the caller pointer
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    // Dynamically allocate an int array of size 'n'
    int* arr = new int[n];

    cout << "Array: ";
    for (int i = 0; i < n; ++i) {
        *(arr + i) = i * 10;
    }

    printArray(arr, n);
    resizeArray(&arr, n, n*2);

    cout << "Resized Array: ";
    printArray(arr, n*2);

    return 0;
}