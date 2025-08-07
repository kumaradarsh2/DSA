#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) std::cin >> arr[i];

    int target;
    std::cin >> target;

    if (target < 0) target*= -1;
    // Two pointer approach here 
    // Time complexity: O(N) since both pointers move towards each other and traverse array in single pass
    // Space complexity: O(1) since we are not using any extra space

    int left = 0, right = 1;
    while (right < n) {
        int diff = arr[right]-arr[left];
        
        if (diff < target) right++;
        else if (diff > target) left++;
        else break;
    }

    std::cout << arr[left] << " " << arr[right] << std::endl;

    return 0;
}