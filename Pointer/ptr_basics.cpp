#include <iostream>

using namespace std;

// make a function that swaps two numbers

// this is not safer
void oldSwapNum(int* a, int* b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

// this is safer
void swapNum(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} 

int main() {
    // int* ptr;
    // cin >> *ptr;

    // cout << ptr << endl;
/*
    int num;
    cin >> num;

    int* ptr = &num;

    cout << ptr << endl;
    cout << *ptr+1 << endl;
*/

/****************************************************************************************/
// printing elements of array
/*
    int n;
    cin >> n;

    int arr[n];

    // arr[i] = arr+i #inside the computer's memory
    // arr ==> base address of array or address of the first element of array
    // 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    } 

    int* ptr = arr;
    while (ptr != arr+n) {
        cout << *ptr++ << " ";
    } 
    cout << endl;
*/

/***************************************************************************************/

/*
// swapping two numbers
    int x = 5, y = 3;
    swapNum(&x, &y);

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
*/

/***************************************************************************************/
    // character string
    // char ch;
    // cin >> ch;

    // char* ptr = &ch;
    // cout << *ptr << endl;

    // character array
    char greet[10] = "Hello";

    // int index = 0;
    // cout << (void*) (greet + 3) << endl;

    // for (int i = 0; i < 10; ++i) {
    //     cout << (void*) (greet + i) << endl;
    //     if (greet[i] == '\0') cout << "NULL" << " ";
    // } 
    // cout << endl;
    // int size = sizeof(greet)/sizeof(char);

    // for (int i = 0; i < size; ++i) cout << greet[i];
    // cout << endl;
    int size = 0;

    //  a void* is a generic pointer that can point to any type, but it cannot be directly assigned to a char* without an explicit cast because void* lacks type information.

    char* ptr = &greet[size];
    cout << (void*) ptr << endl;

    while (*ptr != '\0') {
        size++, ptr++;
    }

    // cout <<  (greet[size] == '\0' ? "NULL" : "something else") << endl;
    cout << size << endl;

    // test finished
    cout << "finished" << endl;

    return 0;
}
