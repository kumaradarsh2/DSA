// Important concept to remember to get correct inserted position of element in array

#include <iostream>
#include <vector>

int insertPosition(std::vector<int> arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;
    int index = n; // default index

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) {
            index = mid; // potential insert position
            high = mid - 1;
        }
        else {
            // arr[mid] < target
            low = mid + 1; // no potential index to left of low (inclusive)
        }
    }
    return index;
}

int main() {
    std::vector<int> arr = {1,4,6,8,10,14,16,18};
    int element = 20;

    // Method 1: Linear Search
/*
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > element) {
            std::cout << "Insert Position: " << i << std::endl;
            break;
        }
    }
*/

    // Method 2: Binary Search
    int pos = insertPosition(arr, element);
    std::cout << "Insert Position: " << pos << std::endl;

    return 0;
}