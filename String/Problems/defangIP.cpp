#include <iostream>
#include <string>

using namespace std;

int main() {
    string address = "1.1.1.1";

    string defanged;

    for (char ch : address) {
        // Used ternary operator here
        defanged += (ch == '.') ? "[.]" : "1";
    }

    cout << defanged << endl;

    return 0;
}