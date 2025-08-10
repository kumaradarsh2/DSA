#include <iostream>
#include <set>

using namespace std;

class Person{
public:
    int age;
    string name;

    bool operator < (const Person &other) const {
        return age < other.age;
    }

};

int main() {
    // set: unique + sorted
    // multiset: sorted (not unique)
    // unordered_set: unique (not sorted)
    // unoredered_multiset: not unique (not sorted either)

    set<int> st; 

    st.insert(20);
    st.insert(10);
    st.insert(40);
    st.insert(50);
    st.insert(10);
    st.insert(20);

    for (set<int>::iterator it = st.begin(); it != st.end(); ++it) cout << *it << " ";
    cout << endl;

    // find => returns the iterator of that element
    if (st.find(50) != st.end()) cout << "found\n";
    else cout << "not found\n"; 

    // count --> count of the element
    if (st.count(10)) cout << "yes";
    else cout << "no";
    cout << endl;
    // we can also use .cout() method which returns 0 or 1 based on whether element is present in set 

    // delete
    st.erase(40);

    // we can sort elements in decending order using greater<type>
    set<int, greater<int>> s; // unique value will still be there
    
    s.insert(20);
    s.insert(10);
    s.insert(40);
    s.insert(50);
    s.insert(10);
    s.insert(20);

    // for (set<int>::iterator it = s.begin(); it != s.end(); ++it) cout << *it << " ";
    // cout << endl;
    for (auto val : s) cout << val << " ";
    cout << endl;

    set<Person> classset;

    Person p1, p2, p3;
    p1.age = 10, p1.name = "adarsh";
    p2.age = 12, p2.name = "mohit";
    p3.age = 22, p3.name = "camel";

    classset.insert(p1);
    classset.insert(p2);
    classset.insert(p3);

    for (auto it = classset.begin(); it != classset.end(); ++it) {
        cout << (*it).age << " " << (*it).name << endl;
    }

    // multiset concept
    multiset<int> ms;

    ms.insert(30);
    ms.insert(10);
    ms.insert(40);
    ms.insert(30);
    ms.insert(30);
    ms.insert(20);
    ms.insert(10);

    ms.erase(30); // all 30s are removed

    for (auto val : s) cout << val << " ";
    cout << endl;

    return 0;
}