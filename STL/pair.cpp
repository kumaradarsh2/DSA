#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Declaring a pair
    pair<int, string> p; 

    // Adding elements to our pair
    // p.first = 10;
    // p.second = "Adarsh Kumar";
    
    // or using make_pair
    p = make_pair(20, "Hello");

    cout << p.first << " " << p.second << endl;

    // A simple program to take name and age from the users and then display them
    int n;
    cin >> n;
    
    vector<pair<string, int>> vp(n);
    
    for (int i = 0; i < n; ++i) cin >> vp[i].first >> vp[i].second; 

    for (pair<string, int>& p : vp) cout << p.first << " " << p.second << endl; 

    return 0;
}