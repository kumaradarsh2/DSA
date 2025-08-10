#include <iostream>
#include <list>

using namespace std;

int main() {
    // What is std::list?
    // It's a doubly linked list in C++. 
    // It stores elements in nodes, where each node knows about the previous and next nodes
    // It doesn't store elements at contiguous memory locations 
    // Thus inserting and deleting element anywhere (front, back, middle) is very efficient and takes O(1) time complexity

    list<int> myList;

    myList.push_back(30);
    myList.push_back(50);
    myList.push_front(20);
    myList.push_front(80);

    // to print size of list
    cout << myList.size() << endl; 

    // 80 20 30 50
    for (int val : myList) cout << val << " ";
    cout << endl;

    // Remove element
    myList.pop_back(); // 50 is removed
    myList.pop_front(); // 80 is removed

    for (int val : myList) cout << val << " ";
    cout << endl;

    // Using iterator
    // auto == list<int>::iterator
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << endl;
    }

    // Note: Direct indexing doesn't work, we must iterate to access element
    // myList[0] doesn't work, throws error

    // How we insert before position of iterator? 
    // Use: .insert(iterator, value);

    // Insert after the first element
    auto it = myList.begin();
    ++it; // move iterator to second element
    myList.insert(it, 96); // this inserts 96 before the position of iterator

    return 0;
}

// When to use std::list over std::vector?
/*
    1. when we need fast insertion and deletion at random positions
    2. when random access if required, use std::vector instead not std::list

*/