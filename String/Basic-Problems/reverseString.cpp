#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverseString(string& str) {
    int left = 0, right = str.size()-1;
    while (left < right) {
        swap(str[left], str[right]);
        left++, right--;
    }
}

int main() {
    // given a string we have to reverse it
    // Approach: Use two pointer technique to reverse it 
    string str = "Adarsh";
    
    reverseString(str);

    cout << str << endl;

    return 0;
}