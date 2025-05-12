#include <iostream>
#include <vector>
#include <algorithm> // for std::max

int findPeakIndex(std::vector<int> arr) {
    int low = 0, high = arr.size()-1;

    while (low < high) {
        int mid = low + (high-low) / 2;
        if (arr[mid] < arr[mid+1]) low = mid + 1; 
        else high = mid;
    }
    return low;
}

int main() {
    std::vector<int> arr = {2,4,6,8,10,6,5};

    // Method 1: Bruteforce
    // Approach: Since peak index in Mountain Array is the largest element, we just find the largest
/*
    int largest = arr[0];
    int index = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > largest) {
            largest = arr[i];
            index = i;
        }
    }

    std::cout << "Peak index: " << index << std::endl;
*/
/****************************************************************************************************/

    // Method 2: Binary Search
    int peakIndex = findPeakIndex(arr);
    std::cout << "Peak Index: " << peakIndex << std::endl;

    return 0;
}