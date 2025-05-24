// Problem: Divide an Array into equal parts such that their sum is equal
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {3,4,-2,5,8,20,-10,8};
    int n = arr.size();
    bool canBeDivided = false;
    // Method 1: Bruteforce Approach
    // Time complexity: O(n*2n) = O(2n^2) = O(n^2)
    // Space complexity: O(1) since no extra space being used
    /*
    
    for (int i = 0; i < n-1; ++i) {
        int sum1 = 0, sum2 = 0;

        for (int j = 0; j <= i; ++j) sum1 += arr[j];
        
        for (int j = i+1; j < n; ++j) sum2 += arr[j];

        if (sum1 == sum2) {
            canBeDivided = true;
            std::cout << "Yes, Divided at index " << i << std::endl;
            break;
        }
    }

    
    */

    // Method 2: Using Prefix Sum
    // First calculate totalSum
    int totalSum = 0;
    for (int elem : arr) totalSum += elem;

    int prefixSum = 0;
    for (int i = 0; i < n-1; ++i) {
        prefixSum += arr[i];
        int ans = totalSum - prefixSum;

        if (ans == prefixSum) {
            canBeDivided = true;
            std::cout << "Yes, Divided at index " << i << std::endl;
            break;
        }
    }

    if (!canBeDivided)
            std::cout << "No, Can't be divided into equal sum" << std::endl;

    return 0;
}