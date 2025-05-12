#include <iostream>

int cubeRoot(int n) {
    int low = 1, high = n;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high-low) / 2;
        // Type casting mid to long long here to let the compiler do arithmetic in long long and thus avoid integer overflow due to mid*mid*mid in integer arithmetic and then assigning the long long obatained result to long long product
        long long product = (long long) mid*mid*mid;
        if (product == n) return mid;
        else if (product < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int x;
    std::cin >> x;

    std::cout << cubeRoot(x) << std::endl;

    return 0;
}