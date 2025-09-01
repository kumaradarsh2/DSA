#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    // get size
    // Method 1: Use .size() method since std::string is an object
    
    // Method 2: Do it manually
    int size = 0; // it is kinda acting like a pointer too
    while (str[size] != '\0') {
        size++;
    }

    cout << size << endl;

    return 0;
}