#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    std::vector<int> arr = {-2,-4};
    int n = arr.size();

    // Generate all the subarrays and take the maximum sum
    // Time complexity: O(N^3)
    // Space complexity: O(1)
    int maxSum = INT_MIN;
/*
    for (int size = 1; size <= n; ++size) {
        for (int i = 0; i <= n-size; ++i) {
            int subArrSum = 0;
            for (int j = i; j < i+size; ++j) {
                subArrSum += arr[j]; 
            }
            maxSum = std::max(subArrSum, maxSum);
        }
    }
*/

/*************************************************************************************************/
    // Method 2: 
    // Time complexity: O(N^2)
    // Space complexity: O(1)
    /*
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            maxSum = std::max(sum, maxSum);
        }
    }
    */
/*************************************************************************************************/

    // Method 3: Using Kandane's Algorithm
    // Time complexity: O(N)
    // Space complexity: O(1)

    int prefix = 0;

    for (int i = 0; i < n; ++i) {
        prefix += arr[i];

        maxSum = std::max(prefix, maxSum);

        // Whenever we see negative prefix, make it zero 
        //          -- Kandane's Algorithm
        if (prefix < 0) prefix = 0;
    }

    std::cout << maxSum << std::endl;

    return 0;
}