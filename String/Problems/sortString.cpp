#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin >> str;

    // Method 1: Use std::sort() function 
    sort(str.begin(), str.end());

    // Method 2: Do manual sorting
    // later

    cout << str << endl;

    return 0;
}