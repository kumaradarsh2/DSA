#include <iostream>
using namespace std;

// factorial of a number
/*
int fact(int n) {
    if (n == 0 || n == 1) return 1;

    return n * fact(n-1);
}
*/

/**************************************************************************************/
// power of two
/*
int powerOfTwo(int n) {
    if (n == 0) return 1;
    
    return 2 * powerOfTwo(n-1);
}
*/

/**************************************************************************************/
// sum of squares of N numbers
int sumOfSq(int n) {
    if (n == 1) return 1;
    return n*n + sumOfSq(n-1);
}

int main() {
    int n;
    cin >> n;
    // cout << fact(n) << endl;
    // cout << powerOfTwo(10) << endl;
    cout << sumOfSq(n) << endl;

    return 0;
}
