#include <iostream>
#include <vector>

int main() {
    // Find the missing number present in array of size n-1
    // Elements range from 1 to n (inclusive)
    std::vector<int> arr = {1,2,3,4,6};
    int n = arr.size();

    // Method 1: Using hashing technique

    // Time complexity: O(N+N+1) = O(2N+1) = O(N)
    // Space complexity: O(N+1) = O(N)

    // Create a hash array
    /*
    std::vector<bool> freqArr(n+1);

    for (int elem : arr) {
        freqArr[elem-1] = 1;
    }

    // Now check for missing value
    for (int i = 0; i < freqArr.size(); ++i) {
        if (freqArr[i] == 0) {
            std::cout << "Missing element: " << i+1 << std::endl;
            break;
        }
    }
    */
   /********************************************************************************************/

   // Method 2: Using simple math
   // Sum of elements from 1 to N (N = n+1)

   // Time complexity: O(N) since we are iterating in arr "n" times
   // Space complexity: O(1) since no extra space taken

   int N = n+1; // this is the total number of elements 
   int sumTotal = N * (N+1) / 2;

   int sumArr = 0;
   for (int elem : arr) sumArr += elem;

   int missingElem = sumTotal - sumArr;

   std::cout << missingElem << std::endl;
    
    return 0;
}