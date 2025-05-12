#include <iostream>
#include <vector>

int countZeroes(std::vector<int> &arr) {
    // Binary Search
    int low = 0, high = arr.size()-1;
    int firstOcc = -1, lastOcc = high;
    
    while (low <= high) {
        int mid = low + (high-low) / 2;
        if (arr[mid] == 1) low = mid + 1;
        else {
            firstOcc = mid; 
            high = mid - 1;
        }
    }
    return lastOcc - firstOcc + 1;
}

int main() {
    // Method 1: Using bruteforce
    // Do a linear iteration and count number of zeros
    std::vector<int> arr = {1,1,1,1,1,1,1,1,1,0,0,0};

/*
    int numOfZeros = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) numOfZeros++;
    }

    std::cout << numOfZeros << std::endl;
*/ 
 
/**************************************************************************************************/
    int zeros = countZeroes(arr);
    std::cout << zeros << std::endl;

    return 0;
}