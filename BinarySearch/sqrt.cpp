#include <iostream>

int sqrt(int num) {
    int low = 0, high = num;
    int ans = -1;
    while (low <= high) {
        // Used long long to avoid integer overflow (check for INT_MAX)
        long long mid = low + (high - low) / 2;
        if (mid*mid == num) return mid;
        else if (mid*mid < num) {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

int main() {
    int x;
    std::cin >> x;

    // Method 1: Bruteforce
    // Time complexity: O(√n)
    // Space complexity: O(1) since no extra space needed
/*
    for (int i = 1; i <= x; ++i) {
        if (i*i == x) {
            std::cout << "Square root of " << x << ": " << i << std::endl;
            break;
        }
        else if (i*i > x) {
            // returning floor value
            std::cout << "Square root of " << x << ": " << i-1 << std::endl;
            break;
        }
    }
*/
/***************************************************************************************/
    // Method 2: Binary Search on answers
    // Time complexity: O(log N)
    // Space complexity: O(1) since no extra space needed

    std::cout << sqrt(x) << std::endl;

    return 0;
}