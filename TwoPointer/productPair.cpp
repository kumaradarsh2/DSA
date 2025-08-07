#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {3,7,8,11,25};
    int n = arr.size();
    
    int target = 56;

    int left = 0, right = n-1;
    while (left < right) {
        int product = arr[left]*arr[right];

        if (product == target) break;
        else if (product < target) left++;
        else right--;
    }

    std::cout << arr[left] << " " << arr[right] << std::endl;

    return 0;
}