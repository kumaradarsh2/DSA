// Array Allocation

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* arr = new int[n]; // dynamic array

    for (int i = 0; i < n; ++i) arr[i] = i+1;
    
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;

    // notice how we getting dangling values here
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;

    return 0;
}