// Divide array into Sub Arrays such that their sum is equal
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {3,4,-2,5,8,20,-10,8};
    int n = arr.size();

    bool sumExists = false;

    // Method 1
    // Time complexity: O(N*N) = O(N^2)
    // Space complexity: O(1) since we are not using any extra space
/*
    for (int k = 0; k < n; k++) {
        int prefixSum = 0, suffixSum = 0;
        for (int i = 0; i < n; i++) {
            if (i < k) prefixSum += arr[i];
            else suffixSum += arr[i];
        }
        // Print statement for debugging
        std::cout << "Prefix Sum: " << prefixSum << " Suffix Sum: " << suffixSum << std::endl;

        // Compare sum here
        if (prefixSum == suffixSum) {
            sumExists = true;
            std::cout << true << std::endl;
            break;
        } 
    }

*/
/*********************************************************************************************/
    // Method 2
    // Time complexity: O(N)
    // Space complexity: O(1)

    // Approach: 
    // First we calculate total sum
    int totalSum = 0;
    for (int elem : arr) totalSum += elem;

    int prefixSum = 0;
    for (int i = 0; i < n-1; ++i) {
        prefixSum += arr[i];
        int suffixSum = totalSum - prefixSum;

        // Print statement for debugging
        std::cout << "Prefix Sum: " << prefixSum << " Suffix Sum: " << suffixSum << std::endl;

        if (prefixSum == suffixSum) {
            sumExists = true;
            std::cout << true << std::endl;
            break;
        }
    }

    if (!sumExists) std::cout << false << std::endl;

    return 0;
}
