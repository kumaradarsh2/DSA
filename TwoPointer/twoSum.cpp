#include <iostream>
#include <vector>

// binary search function
int binarySearch(std::vector<int> arr, int target, int startingIndex) {
    int low = startingIndex, high = arr.size()-1; 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (target > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    std::vector<int> arr = {3,2,4};
    int n = arr.size();
    int target = 22;

    // Method 1: Using brute-force
/*
    for (int i = 0; i < n-1; ++i) {ls
        for (int j = i+1; j < n; ++j) {
            if (arr[i] + arr[j] == target) {
                std::cout << arr[i] << " " << arr[j] << std::endl;
                break;
            }
        }
    }
*/
/************************************************************************************************************/
    // Method 2: Using binary search
    // Approach: for any element x, we need to find target-x in subarray and since entire array is sorted, we can apply binary search here to optimize the previous solution

    // Time complexity: O(N logN)
    // Space complexity: O(1) since not using any extra space

/*
    int i, targetIndex;
    for (i = 0; i < n-1; ++i) {
        int newTarget = target-arr[i];
        // use binary search here to find newTarget in the subarray [i+1, n-1]
        targetIndex = binarySearch(arr, newTarget, i+1);
        if (targetIndex != -1) break;
    }

    std::cout << arr[i] << " " << arr[targetIndex] << std::endl;
*/

    // Method 3: Using Two pointer approach
    // Note: First we need sorted array for this approach to work.
    // Imp: left pointer increases the value and right pointer decreases the sum value

    // Time complexity: O(N) since both pointers converse and thus traverse the array in single pass
    // Space complexity: O(1)
    int left = 0, right = n-1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum > target) right--;
        else if (sum < target) left++;
        else break;
    }

    std::cout << arr[left] << " " << arr[right] << std::endl;

    return 0;
}