#include <iostream>
#include <numeric>

using namespace std;

// assuming a > b
int gcdOfNums(int a , int b) {
    if (b == 0) return a;
    return gcdOfNums(b, a%b);
}

int main() {
    int num1, num2;
    cin >> num1 >> num2;

    // Using c++ std::gcd() function
    // Time complexity: O(N)
    /*
    int result = gcd(num1, num2);
    */

    // Method 2: using Eucleadian algorithm which states that: gcd(a, b) == gcd(b, a % b) assuming a > b

    int result;

    if (num1 > num2)
        result = gcdOfNums(num1, num2);
    else 
        result = gcdOfNums(num2, num1);

    cout << result << endl;

    return 0;
}