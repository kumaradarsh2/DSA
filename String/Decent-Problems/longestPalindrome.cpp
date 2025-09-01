#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    // we have to give length of longest palindrome
    int size = 0;

    vector<int> lower(26), upper(26);

    for(char s : str) {
        if (s-0 >= 97)
        lower[s-97]++;

        if (s-0 >= 65)
        upper[s-65]++;
    }

    for (int elem : lower) cout << elem << " ";
    cout << endl;

    int odd = 0;

    for (int elem : lower) {
        if (elem % 2) {
            odd = 1;
            elem--;
        }
        size += elem;
    }

    for (int elem : upper) {
        if (elem % 2) {
            odd = 1;
            elem--;
        }
        size += elem;
    }

    cout << size + odd << endl;

    return 0;
}