#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxArr(const vector<int>& arr) {
        int maxi = arr[0];
        for (int elem : arr) maxi = max(maxi, elem);
        return maxi;
    }

    int sumArr(const vector<int>& arr) {
        int total = 0;
        for (int elem : arr) total += elem;
        return total;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = maxArr(nums), high = sumArr(nums);
        int n = nums.size();
        int ans = high;
        while (low <= high) {
            int subArr = 1, numbers = 0;
            int mid = low + (high - low) / 2;
            for (int num : nums) {
                numbers += num;
                if (numbers > mid) {
                    subArr++;
                    numbers = num;
                }
            }

            // check if distribution is possible or not
            if (subArr <= k) {
                // success
                ans = mid;
                // look for lower maximum value now
                high = mid - 1;
            } 
            else {
                // failure: distribution not possible
                // look for higher maximum value so that distribution is possible
                low = mid + 1;
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
        int result = obj.splitArray(numbers, k);

        cout << result << endl;
    }

    return 0;
}
