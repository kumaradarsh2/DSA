#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // It contains only unique elements in any order
    // Search, Insert and Delete has O(1) average constant time complexity
    // Uses Hashing under the hood 
   
    unordered_set<int> st;
    
    st.insert(10);
    st.insert(80);
    st.insert(10);
    st.insert(20);
    st.insert(10);
    st.insert(30);
    st.insert(40);
    
    for (auto s : st) cout << s << " ";
    cout << endl;

    cout << st.count(80) << endl;
    
    return 0;
}