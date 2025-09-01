#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

int main() {
    string str = "Myself2 Me1 I4 and3";
    string subString;

    vector<string> strVec(9);

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            int index = subString.back() -'0';
            subString.pop_back();

            strVec[index-1] = subString;

            subString.clear();
        }
        else {
            subString.push_back(str[i]);
        }
    }

    int index = subString.back() - '0';
    subString.pop_back();

    strVec[index-1] = subString;

    string sortedStr;

    for (string s : strVec) {
        if (s.size()) sortedStr.append(s + " ");
    }

    sortedStr.pop_back(); // remove the last space
    
    cout << sortedStr << endl;

    return 0;
}