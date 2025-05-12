#include <iostream>
#include <vector>

int main() {
    // Given array
    std::vector<int> arr = {1,2,3,4,5};

    // Method 1
    /*
    // Reverse array
    std::vector<int> brr; // creating empty vector brr

    // Logic: Read element from the end of arr and keep pushing to brr
    // We are using O(N) time and O(N) extra space

    int n = arr.size() - 1;

    for (int i = n; i >= 0; --i){
        brr.push_back(arr[i]);
    }

    // Printing brr 
    for (int elem : brr) std::cout << elem << " ";
    std::cout << std::endl;

    */
/**************************************************************************************************/

    // Optimize the naive solution using two pointer approach
    // Note: pointers in two-pointer approach are indexes

    // Time complexity: O(N/2) = O(N)
    // Space Complexity: O(1) [doing it in place, no extra space needed]

    int left = 0, right = arr.size()-1;

    while (left <= right) {
        std::swap(arr[left], arr[right]);
        left++, right--;
    }

    // Print the reversed array in place (i.e. no extra space or memory is used)
    for (int elem : arr) std::cout << elem << " ";
    std::cout << std::endl;

    return 0;
}