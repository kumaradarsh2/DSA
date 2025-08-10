#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    // unique keys are present (duplicate keys are not present)
    // no sorted order of keys

    unordered_map<string, int> mp;

    mp.insert(make_pair("Adarsh", 21));
    mp.insert(make_pair("Shyam", 18));
    mp.insert(make_pair("Mohan", 15));
    mp.insert(make_pair("Rahul", 76));
    mp.insert(make_pair("Lalan", 45));

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << (*it).first << " " << (*it).second << endl;
    }

    return 0;
}