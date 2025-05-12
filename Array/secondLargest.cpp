#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <climits> // for INT_MIN or INT_MAX

int main() {
    std::vector<int> arr = {3, 4, 5, 2, 1, 2, 5, 4};
    int n = arr.size();

    // Naive bruteforce approach

    // Time complexity: O(logN + N)
    // Space complexity: O(1) // No extra memory being used
    /*
    std::sort(arr.begin(), arr.end());

    int largest = arr[n-1];

    for (int i = n-1; i >= 0; --i) {
        if (arr[i] != largest) {
            std::cout << "Second Largest: " << arr[i] << std::endl;
            break;
        }
    }
    */

    /*********************************************************************************/
    // Let's try to find better solution of better Time complexity
    // Approach: Find largest in one iteration and optimise the O(log N) complexity
    //           Find second largest in second iteration as before

    // Time complexity: O(N + N) = O(2N)
    // Space complexity: O(1) // No extra space being used
    int largest = arr[0], slargest = INT_MIN;
    /*
    for (int elem : arr) {
        largest = std::max(elem, largest);
    }

    for (int elem : arr) {
        if (elem != largest) {
            slargest = std::max(elem, slargest);
        }
    }
    */
    /**************************************************************************************/
    // Now we will optimize the O(2N) time complexity to get the most optimal solution which runs in half the time i.e. in O(N) time

    // Time complexity: O(N)
    // Space complexity: O(1)
    for (int elem : arr) {
        if (elem > largest) {
            slargest = largest;
            largest = elem;
        } 
        else if (elem < largest && elem > slargest) slargest = elem;
    }

    std::cout << "Second Largest: " << slargest << std::endl;

    return 0;
}