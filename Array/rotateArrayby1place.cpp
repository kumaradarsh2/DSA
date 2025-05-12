#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {1,2,3,4,5};
    int n = arr.size();

    // For both left and right rotation
    // Rotate right by 1 place
    // Time complexity: O(N)

    // Space complexity: O(1) since no extra is used
    /*
    int temp = arr[n-1];

    for (int i = n-1; i > 0; i--) {
        arr[i] = arr[i-1];
    }

    arr[0] = temp;
    */

    // Rotate left by 1 place
    int temp = arr[0];

    for (int i = 1; i < n; ++i) {
        arr[i-1] = arr[i];
    }

    arr[n-1] = temp;

    // Print the array
    for (int elem : arr) std::cout << elem << " ";
    std::cout << std::endl;

    return 0;
}