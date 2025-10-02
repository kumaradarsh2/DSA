// This program effectively counts the total number of words in a given sentence, it accounts for extra spaces, punctuation, commans, etc. and gives the effective number of words

#include <iostream>
#include <string>
#include <cctype>
#include <utility>

using namespace std;

pair<int, int> wordCount (string& sentence) {
    int count = 0, charCount = 0;
    bool inword = false;
    
    for (char s : sentence) {
        charCount++;
        if (isalnum(s) || s == '\'') {
            if (!inword) {
                count++;
                inword = true;
            }
        }
        else {
            inword = false;
        }
    }

    return make_pair(count, charCount);
}

int main () {
    string input;
    getline(cin, input);

    pair<int, int> result = wordCount(input);

    int words = result.first;
    int characters = result.second;

    cout << "Words: " << words << endl;
    cout << "Characters: " << characters << endl;

    return 0;
}
