// Print even numbers from 'n' to '1', given n is even
#include <iostream>

using namespace std;

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