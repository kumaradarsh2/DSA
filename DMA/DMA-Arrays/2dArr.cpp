#include <iostream>

using namespace std;

int main() {
    // Initialization
    // For 2d array we need to get the addresses of 1d arrays (each size 'm')
    // We store these address in 1d array of size 'n'
    // And we point to the base address of this 1d array
    int n, m;
    cin >> n >> m;

    // we basically create a 1-d Array which stores the addresses (pointers) of the 1d arrays
    int** ptr = new int* [n];

    for (int i = 0; i < n; ++i) {
        *(ptr + i) = new int[m];
    }

    // getting the values
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> *(*(ptr + i) + j);
        }
    }

    cout << "\nOutput: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << *(*(ptr + i) + j) << " ";
        }
        cout << endl;
    }
    
    // deallocation
    // freeing up the memory 

    // first free up all the arrays
    for (int i = 0; i < n; ++i) {
        delete[] *(ptr + i);
    }

    // now free up this array itself
    delete[] ptr;

    cout << "\nmemory freed now" << endl;

    return 0;
}