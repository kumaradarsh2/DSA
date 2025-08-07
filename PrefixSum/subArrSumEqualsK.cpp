#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {1,2,3};
    int n = arr.size();

    int k = 3;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int prefix = 0;
        for (int j = i; j < n; ++j) {
            prefix += arr[j];
            if (prefix == k) {
               count++; 
            }
        }
    }
    
    cout << count << endl;

    return 0;
}