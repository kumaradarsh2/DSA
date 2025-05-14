#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    std::vector<int> arr = {4,-6, 2, 8};
    int n = arr.size();

    // Generate all the subarrays and take the maximum sum
    int maxSum = INT_MIN;

    for (int size = 1; size <= n; ++size) {
        for (int i = 0; i <= n-size; ++i) {
            int subArrSum = 0;
            for (int j = i; j < i+size; ++j) {
                subArrSum += arr[j]; 
            }
            maxSum = std::max(subArrSum, maxSum);
        }
    }

    std::cout << maxSum << std::endl;

    return 0;
}