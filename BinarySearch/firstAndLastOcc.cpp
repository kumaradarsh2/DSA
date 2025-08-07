// Find the first and Last Occurrence of an element in the array

#include <iostream>
#include <vector>

int findOccurrence(std::vector<int> arr, int target, char occ) {
    int low = 0, high = arr.size() - 1;
    int index = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            index = mid;
            if (occ == 'f'){
                // Keep searching to the left for first occurrence
                high = mid - 1; 
            } else {
                // Keep going to the right for last occurrence
                low = mid + 1;
            }
        }
        else if (target > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return index;
}

int main() {

// Bruteforce approach
/*  
    int firstOcc = -1, lastOcc = -1;
    int target = 10;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
          if (firstOcc == -1 ) 
            firstOcc = i, lastOcc = i;
          else lastOcc = i;
        }
    }
    cout << firstOcc << " " << lastOcc << endl;
*/

    // Binary Search Method
    std::vector<int> vec = {5,7,7,8,8,10};
    int search = 7;

    int firstOcc = findOccurrence(vec, search, 'f');
    int lastOcc = findOccurrence(vec, search, 'l');

    std::cout << "First Occurrence of " << search << " at index: " << firstOcc << std::endl;
    std::cout << "Last Occurrence of " << search << " at index: " << lastOcc << std::endl;

    // Number of Occurrences
    int numberOfOcc = lastOcc - firstOcc + 1;
    std::cout << "Number of Occurrences of " << search << ": " << numberOfOcc << std::endl;

    return 0;
}