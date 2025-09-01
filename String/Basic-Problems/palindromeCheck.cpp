#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    bool isPalindrome = true;

    // Approach: Use two pointer and compare the characters from both ends
    int left = 0, right = str.size()-1;
    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = false;
            break;
        }
        left++, right--;
    }

    cout << isPalindrome << endl;

    return 0;
}