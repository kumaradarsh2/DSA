#include <iostream>
#include <vector>

// Time Complexity: O(log N)
// Space Compexity: O(1)
int binarySearch(std::vector<int> arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (target > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }

    return -1; // target not found
}

int main() {
    std::vector<int> arr = {1,2,3,4,5};
    int search = 3;

    // There are two ways to search an element in an array

    // Method 1: Using Linear Search
    // Time Complexity: O(N)
    // Space Compexity: O(1) since we are not using any extra space
    /*
    bool found = false;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == search) {
            found = true;
            std::cout << "Element found at " << i << " index" << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Element not present in the array" << std::endl;
    }
    */

    // Method 2: Using Binary Search
    int index = binarySearch(arr, search);

    if (index != -1) {
        std::cout << "Target found at index " << index << std::endl;
    } else {
        std::cout << "Target not found!" << std::endl;
    }

    return 0;
}