#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
bool isPalindrome(string str, int left, int right) {
    if (left >= right) return true;

    if (str[left] == str[right]) 
        return isPalindrome(str, left+1, right-1);
    return false;
}
*/

// accumulator method, feels like a loop
/*
int countVowels(string str, int count, int index, int n) {
    if (index == n) return count;

    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u') count++;

    return countVowels(str, count, index+1, n);
}
*/
bool checkVowel(string str, int index) {
    if (str[index] == 'a' || str[index] == 'e' || str[index] == 'i' || str[index] == 'o' || str[index] == 'u') return true;
    return false;
}

// functional recursion
int countVowels(string str, int index, int n) {
    // base case
    if (index == n) return 0;

    bool isVowel = checkVowel(str, index);
    int add = (isVowel ? 1 : 0);

    return add + countVowels(str, index+1, n);
}

void reverseString(string& str, int left, int right) {
    if (left >= right) return;

    swap(str[left], str[right]);
    reverseString(str, left+1, right-1);
}

string upper(string str, int index) {
    if(index == -1) return "";

    char add = 'A' + str[index] - 'a';

    return upper(str, index-1) + add;
}

int main(){
    string str = "amazonai";
    int n = str.size();

    // reverseString(str, 0, n-1);

    str = upper(str, n-1);
    cout << str << endl;

    // cout << countVowels(str, 0, n) << endl;
    // cout << (isPalindrome(str, 0, 4) == true ? "true" : "false") << endl;

    return 0;
}