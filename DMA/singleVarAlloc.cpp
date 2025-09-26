// Single Variable Allocation

#include <iostream>

using namespace std;

int main() {
    int* p = new int; // allocates memory, uninitialized (garbage value inside)
    *p = 42; // assign value
    cout << *p << endl;

    delete p; // free memory
    cout << *p << endl; // What we see the output is a "dangling pointer"

    
    // A dangling pointer is a (non-NULL) pointer which points to unallocated (already freed) memory area.

    return 0;
}