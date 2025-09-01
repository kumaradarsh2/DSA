#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A panagram is when it contains all letters of English Alphabet at least once
int main() {
    // all letters are going to be lowercase
    string sentence = "leetcode"; 

    bool isPanagram = true;

    // Brute force
/*
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        bool found = false;
        for (char s : sentence) {
            if (s == ch) {
                found = true;
            }
        }

        if (!found) {
            isPanagram = false;
            break;
        }
    }


*/

     vector<bool> letters(26);
     int seen = 0;
     for (char ch : sentence) {
        // check if letter is already not seen
        if (!letters[ch - 'a']) {
            letters[ch - 'a'] = 1;
            seen++;
        }
        if (seen == 26) break; // short-circuiting early if all letters are seen at least once
     }

     // check
     for (bool letter : letters) {
        if (letter == 0) { 
            isPanagram = false;
            break;
        }
     }

    if (isPanagram) cout << "Panagram\n";
    else cout << "Not Panagram\n";
    
    return 0;
}