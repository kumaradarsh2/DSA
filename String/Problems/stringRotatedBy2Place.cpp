#include <iostream>
#include <string>

using namespace std;

string& clockwise(string& str) {
    int n = str.size();
    char temp = str[n-1];
    for (int i = n-1; i > 0; --i) {
        str[i] = str[i-1];
    }
    str[0] = temp;

    return str;
}

string& antiClockwise(string& str) {
    int n = str.size();
    char temp = str[0];
    for (int i = 1; i < n; ++i) {
        str[i-1] = str[i];
    }
    str[n-1] = temp;

    return str;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    string copy = str1;

    // rotate either cw or acw and check if str1 == str2

    // rotate cw twice
    string rotatedCW = clockwise(clockwise(str1));
    // rotate acw twice
    string rotatedACW = antiClockwise(antiClockwise(copy));

    if (str2 == rotatedCW || str2 == rotatedACW) {
        cout << "True" << endl;
    }
    else cout << "False" << endl;

    return 0;
}