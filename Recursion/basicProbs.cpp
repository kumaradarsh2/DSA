#include <iostream>
using namespace std;

/*
// Print even numbers from 'n' to '1', given n is even
void print(int n) {
    if (n == 0) {
        cout << endl;
        return;
    }
    cout << n << " ";
    print(n-2);
}

int main() {
    int n;
    cin >> n;

    cout << "Even numbers: ";
    print(n);

    return 0;
}
*/

/******************************************************************************************/

// Print number from 1 to N with only one argument

void Print(int N) {
    if (N == 1) {
        cout << N << endl;
        return;
    }
    Print(N-1);
    cout << N << endl;
}

int main() {
    Print(5);

    return 0;
}
