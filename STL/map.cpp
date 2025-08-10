#include <iostream>
#include <map>

using namespace std;

int main() {
    // Map stores data in {key, value} pair (think of everything in terms of keys)
    // Sorted key orders and unique keys
    // Uses Red-Black tree or AVL tree for implementation
    // Search, Insert, Delete takes O(log N) time
    map<int, int> mp;
    mp.insert(make_pair(13, 26));
    mp.insert(make_pair(12, 42));
    mp.insert(make_pair(10, 20));
    mp.insert(make_pair(12, 30));
    mp.insert(make_pair(9, 18));

    // another way to insert and even update 
    mp[11] = 2; // here inserting value 12 for key 40
    
    // if key is not present, it creates key 
    // if key is present, then it updates it
    mp[9] = 81;

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    // making map of key=string and value=int type
    map<string, int> mp2;
    
    mp2.insert(make_pair("Mohan", 15));
    mp2.insert(make_pair("Shyam", 18));
    mp2.insert(make_pair("Adarsh", 21));
    mp2.insert(make_pair("Rahul", 76));
    mp2.insert(make_pair("Lalan", 45));

    for (auto& p : mp2) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}