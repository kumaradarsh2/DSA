#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // store "Adarsh"

    // one way
/*
    char name[] = {'A', 'D', 'A', 'R', 'S', 'H'};

    int arraySize = sizeof(name)/sizeof(char);

    // print the value
    for (int i = 0; i < arraySize; ++i) { 
        cout << name[i] << " ";
    }
    cout << endl;
*/

    // How do we take input?
    // char name[10] = {'2', '3', '4'};

    // int arraySize = sizeof(name)/sizeof(char);
    // cout << arraySize << endl;

    // for (int i = 0; i < 10; ++i) cout << name[i] << " ";
    // cout << "\n";


    // trying to see the garbage value
    char garbage[10];

    // for (int i = 0; i < 10; ++i) {
    //     // We cast to int to see the numeric value of the garbage
    //     std::cout << "Index " << i << ": " << garbage[i] << std::endl;
    // }

    // So we have to tell compiler in advance the size of array
    // Another way is :

    char anotherStr[20] = "Hey there";
    cout << anotherStr << endl;


    // So more flexible way is to use std::string which is a class 
    // Another reason to use string is we don't waste memory which we might have to in traditional C-style arrays as the memory is allocated during runtime dynamically
    string myStr = "Hello world";

    // Since std::string is a class in c++, we can use the .size() method of it
    cout << myStr.size() << endl;
    cout << myStr << endl;

    // How do we take input 
    // declare and then take input
    string input; // declaring
    // cin >> input; // taking input

    // But cin stops reading once it encounters space, tab, or enter
    // To solve that problem, we have std::getline() which takes cin and string as argument

    getline(cin, input);
    cout << "getline output: " << input; // printing the input
    cout << "\n"; // for newline

    // Some methods of string
    /*
        1. String concatenation => we can do simple '+=' in most case, or add two strings using '+' operator or we can use .append() method 
        2. push_back(), pop_back() function works the same in string as well which takes one character as argument, SO FOR ONE CHARACTER ONLY
        3. Another important methods: back(), front() very useful to get the last character
        4. Escape character: It's used to escape the next immediate thing but to print it
    
    */

    return 0;
}