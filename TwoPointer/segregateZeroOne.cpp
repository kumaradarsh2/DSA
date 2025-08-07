#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> arr = {1, 1, 0, 0, 1, 0};
    int n = arr.size();

    // Naive Approach
    
    // This is not two pointer, just old method that I have been using
/*
    int i = 0, j = 1;
    
    while (j < n) {
        if (arr[i] == 0) i++;
        else {
            if (arr[j] == 0) {
                std::swap(arr[i], arr[j]);
                i++;
            }
        }
        j++;
    }
*/
/***********************************************************************************************/
// Standard Approach (Learn this!!!)
// Time complexity: O(N) since both pointers come closer to each other and traverse array in single pass
// Space complexity: O(1) since we didn't create an extra space

int left = 0, right = n-1;

while (left < right) {
    if (arr[left] == 0) left++;
    else { // arr[left] == 1
        if (arr[right] == 0) {
            std::swap(arr[left], arr[right]);
            left++, right--;
        }
        else { // arr[right] == 1
            right--;
        }
    }
}

/**********************************************************************************************/
    // My Approach
    // Not recommended approach: (too abstract, though solves problem but unnecessary logic)

/*
    // Mistake I made:
    
        // I mistook arr[left] for left, but left is pointer which points to index.
        // So, to compare the values or do anything with array element at that index, we do arr[left]
        // and NOT just "left"
    

    while (left < right) {
        if (arr[left] == arr[right]) {
            if (left == 0) left++;
            else right--;
        }
        else { // left != right
            if (arr[left] == 1) {
                std::swap(arr[left], arr[right]);
            }
            left++, right--;
        }
    }
*/


    // Printing the array
    for (int elem : arr) std::cout << elem << " ";
    std::cout << std::endl;

    return 0;
}