#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int low = 1, high = position[n-1]-position[0];

        int ans = high;
        while (low <= high) {
            int ball = 1, force = position[0];
            int mid = low + (high - low) / 2;
            for (int i = 1; i < n; ++i) {
                if (force + mid <= position[i]) {
                    ball++;
                    force = position[i];
                } 
            }
            // check if distribution is possible or not
            if (ball >= m) {
                // success
                ans = mid;
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
        return ans; 
    }
};

vector<int> parseInputArray(const string& input) {
    vector<int> result;
    string s = input.substr(1, input.size() - 2); // remove '[' and ']'
    stringstream ss(s);
    string num;
    
    while (getline(ss, num, ',')) {
        result.push_back(stoi(num));
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To clear newline after reading `t`

    while (t--) {
        string arrInput;
        int k;

        getline(cin, arrInput);  // Reads the line like: [1,2,3,4]
        cin >> k;
        cin.ignore(); // Clear newline after reading `k`

        vector<int> numbers = parseInputArray(arrInput);

        Solution obj;
        int result = obj.maxDistance(numbers, k);

        cout << result << endl;
    }

    return 0;
}
