#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// We can only look for larger element on the right side of the element in array
int main() {
    std::vector<int> arr = {9,5,8,12,2,3,7,4};
    int n = arr.size();

    int maxDiff = INT_MIN;

    // Method 1: Brute-force
    /*
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[j] > arr[i]) {
                int diff = arr[j] - arr[i];
                maxDiff = std::max(diff, maxDiff);
            }
        }
    }
    */

    /*******************************************************************************************/
    // Method 2: 

    // Instead of redunctant finding difference with every right element, we will first find the maximum element on the right of given element and then update the maxDiff
    // We are going to use suffixMax for this

    // Time complexity: O(N + N-1) = O(2N + 1) = O(N) 
    // Space complexity: O(N-1) = O(N)

    // First we create a maxArr 
    /*
    std::vector<int> maxArr(n-1);

    maxArr[n-2] = arr[n-1];

    int maxi = arr[n-1];

    for (int i = n-2; i > 0; --i) {
        maxi = std::max(arr[i], maxi);
        maxArr[i-1] = maxi;
    }

    // taking the difference and taking the maxDiff
    for (int i = 0; i < n-1; ++i) {
        int diff = maxArr[i] - arr[i];
        maxDiff = std::max(diff, maxDiff);
    }
    */

    /*******************************************************************************************/
    // Method 3: We are going to optimize the space complexity
    // Time complexity: O(N)
    // Space complexity: O(1)


    // Approach: First we find maxDiff and then update the maxi for subsequent iterations

    int maxi = arr[n-1];

    for (int i = n-2; i >= 0; i--) {
        maxDiff = std::max(maxi-arr[i], maxDiff);
        maxi = std::max(maxi, arr[i]);
    }

    std::cout << maxDiff << std::endl;

    return 0;
}