#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    //  Method 1: Time complexity: O(2N + N logN) = O(N logN)
    //            Space complexity: O(N)
/*
    // make a string first to store vowel
    string vowel;

    for (char ch : str) {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowel.push_back(ch);
        }
    }

    // sort the vowel now
    sort(vowel.begin(), vowel.end());

    // now place it on correct position on str
    int index = 0;

    // again research about reference value here too
    for (char& ch : str) {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            ch = vowel[index];
            index++;
        }
    }    
*/

/***************************************************************************************************/

// Method 2: Time complexity: O(N + N + 256) = O(2N + 256) = O(N)
//           Space complexity: O(256) = O(1) 
//           For space complexity, we can also think even if input is of million size, the array size is always fixed which means its constant and doesn't change according to input which in Big-O is O(1)
    
    // frequency array mei vowels ke count ko store kr lete h phle
    vector<int> freqVowel(256);

    // First pass: O(N)
    for (char ch : str) {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            freqVowel[ch]++;
        }
    }   

    // because ascii characters lexicographically stored hote h, sorted bhi apne aap hi h already

    // Second Pass: 
    int index = 0;
    for (char& ch : str) { // This outer loop runs N times
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {

            // Now this is going crazy here, I might think at first glance that inner loop runs 256 times every time outer loop runs
            // but "index" is never reset inside the inner loop, it keeps on going
            // which is very powerful detail, this means the inner loop runs upto 256 times only  # very important

            // Hence total complexity is: O(N+256) # very important 

            for (int i = index; i < 256; ++i) {
                if (freqVowel[i])  {
                    ch = i; // type coersion should happen here
                    freqVowel[i]--;
                    index = i; // update the index
                    break; // important significance of break
                }
            }
        }
    }    

    cout << str << endl;

    return 0;
}
