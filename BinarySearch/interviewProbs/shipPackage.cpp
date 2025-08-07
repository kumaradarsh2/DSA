#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    int maxWeights(const vector<int>& arr) {
        int maxi = arr[0];
        for (int elem : arr) maxi = max(maxi, elem);
        return maxi;
    }

    int sumWeights(const vector<int>& arr) {
        int total = 0;
        for (int elem : arr) total += elem;
        return total;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = maxWeights(weights), high = sumWeights(weights);
        int n = weights.size();
        int ans = -1;
        while (low <= high) {
            int dayNumber = 1, weight = 0;
            int mid = low + (high - low) / 2;
            // distribute the random maximum weight all over the "days" days
            for (int i = 0; i < n; ++i) {
                weight += weights[i];
                if (weight > mid) {
                    dayNumber++;
                    weight = weights[i];
                }
            }

            // check if distribution is possible or not
            if (dayNumber <= days) {
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
    string arrInput;
    int days;

    getline(cin, arrInput); // Read full line like "[1,2,3,...]"
    cin >> days;

    vector<int> weights = parseInputArray(arrInput);

    Solution obj;
    int result = obj.shipWithinDays(weights, days);

    cout << result << endl;

    return 0;
}
