// Search in Rotated sorted array

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> arr = {4,6,8,10,1,2};

    // Method 1: bruteforce (linear iteration to find the target)
    // Time complexity: O(N)
    // Space complexity: O(1) since we aren't using any extra space/memory

    // Method 2: Optimal solution using binary search
    // Time complexity: O(log N)
    // Space complexity: O(1) 
    int search;
    std::cin >> search;

    int low = 0, high = arr.size()-1;
    int index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == search) {
            index = mid;
            break;
        }
        // Identify the sorted half
        if (arr[mid] >= arr[low]) {
            // Left half is sorted
            if (search >= arr[low] && search < arr[mid]) {
                // element might be in left half, so we eliminate right half
                high = mid - 1;
            }
            else {
                // element not there in left half, hence we eliminate left half itself
                low = mid + 1;
            }
        }
        else {
            // Right half is sorted
            // Left half is sorted
            if (search > arr[mid] && search <= arr[high]) {
                // element might be in right half, so we eliminate left half
                low = mid + 1;
            }
            else {
                // element not there in right half, hence we eliminate right half itself
                high = mid - 1;
            }
        }
    }

    std::string result = (index == -1) ? "Element not found!" : "Element is found at index " + std::to_string(index);

    // if (index != -1) result += std::to_string(index);

    std::cout << result << std::endl;

    return 0;
}