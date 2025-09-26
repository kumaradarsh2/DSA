#include <iostream>

using namespace std;

// Write a function that increments an integer via pointer
void increment(int* num) {
   (*num)++;
}

// this is how we change the value of a pointer
void setNull(int** p) {
    *p = nullptr;
}

// reference-to-pointer
void reset(int*& p) { p = nullptr; }



int main() {
    int n;
    cin >> n;

    increment(&n);

    cout << n << endl;

    // ptr stores address of n
    int* ptr = &n;

/**********************************************************************************/
/*
    // setting ptr to null pointer using a function
    setNull(&ptr);

    // checking if ptr is equal to null pointer or not
    cout << (ptr == nullptr ? "NULL" : "Not NULL") << endl; 
*/

/**********************************************************************************/
    // now using reference-to-pointer method
/*
    ptr = &n;
    reset(ptr);

    cout << (ptr == nullptr ? "NULL" : "Not NULL") << endl; 
*/

/**********************************************************************************/
    // const with pointers
    
    int a = 10, b = 20;

    // pointer to const int
    const int* p; 

    p = &a;
    
    // *p = 15; // not allowed, we can't change the value of p 
                // but we can point it to different address
    
    p = &b; // allowed

    cout << *p << endl;

    // Imp note: const variable needs an initialization
    // const pointer to int
    int* const q = &a; // we can't make p point somewhere else, but can modify its value
    
    // q = &b; // not allowed

    *q = b; // allowed
    cout << *q << endl;

    // const pointer to const int
    // neither the pointer can be pointed somewhere else nor the value can modified
    const int* const ptr1 = &a;

    // ptr1 = &b; // wrong
    // *ptr1 = b; wrong


    // what is a reference?
    // Reference is basically a constant pointer that automatically dereferences for us

    int x = 15;
    int& ref = x;

    ref = 10;

    cout << ref << endl;

    return 0;
}
