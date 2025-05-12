// We need to find minimum element in Rotated sorted array

#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

int main() {
    std::vector<int> arr = {4,6,8,10,1,2};

    // Method 1: bruteforce (linear iteration to find the minimum)
    // Time complexity: O(N)
    // Space complexity: O(1) since we aren't using any extra space/memory

    // Method 2: Optimal solution using binary search
    // Time complexity: O(log N)
    // Space complexity: O(1) 

    int low = 0, high = arr.size()-1;

    int minElement = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Optimization:
        if (arr[low] <= arr[high]) {
            // entire subarray (from low to high) is sorted
            minElement = std::min(arr[low], minElement);
            break;
        }

        // Identify the sorted half
        if (arr[mid] >= arr[low]) { 
            // Left half is sorted
            minElement = std::min(arr[low], minElement);
            low = mid + 1;
        } 
        else {
            // Right half is sorted
            minElement = std::min(arr[mid], minElement);
            high = mid - 1;
        }
    }

    std::cout << "Minimum Element: " << minElement << std::endl;

    return 0;
}