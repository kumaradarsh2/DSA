// Returning dynamic memory from function

#include <iostream>

using namespace std;

int* makeArray(int n) {
    int* arr = new int[n];

    for (int i = 0; i < n; i++) arr[i] = i*10;

    return arr; // survives even after function ends
}

int main() {
    int* arr = makeArray(5);

    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;

    // See how the values are just the garbage now
    // Unallocated memory we are seeing now
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}