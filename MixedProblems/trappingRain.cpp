#include <iostream>
#include <vector>
#include <algorithm>

/*
// Brute force method

int findLargest(std::vector<int> height, int index, char choice) {
    int largest = -1;
    if (choice == 'r') {
        for (int i = index; i < height.size(); ++i) {
            largest = std::max(height[i], largest);
        }
    }
    else {
        for (int i = index; i >= 0; --i) {
            largest = std::max(height[i], largest);
        }
    }

    return largest;
}
*/

int main() {
    std::vector<int> height = {4,2,0,5,2,6,2,3};
    int n = height.size();

    int trappedRainWater = 0;

    // Optimized the above bruteforce (see function) with trade-off of space and time complexity
    // Time complexity: O(N)
    // Space complexity: O(N)
    // Let's find leftMax and rightMax heightay
    
    // leftMax heightay
    std::vector<int> leftMax(n);
    leftMax[0] = 0;

    for (int i = 1; i < n; ++i) {
        leftMax[i] = std::max(leftMax[i-1], height[i-1]); 
    }

    // rightMax heightay
    std::vector<int> rightMax(n);
    
    rightMax[n-1] = 0;

    for (int i = n-2; i >= 0; --i) {
        rightMax[i] = std::max(rightMax[i+1], height[i+1]);
    }

    for (int i = 0; i < n; ++i) {
        // Now we look for the largest building on right side and left side
        // And take the minimum of both and subtract the building height

        int amount = std::min(leftMax[i], rightMax[i]) - height[i];
        
        if (amount > 0) trappedRainWater += amount;
    }

    std::cout << trappedRainWater << std::endl;

    return 0;
}