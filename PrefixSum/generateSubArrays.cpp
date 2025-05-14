#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {4,3,7,2};
    int n = arr.size();

    // Generate all the possible subarrays
    for (int size = 1; size <= n; ++size) {
        std::cout << "\nSubarrays of size " << size << ": " << std::endl;
        for (int i = 0; i <= n-size; ++i) {
            for (int j = i; j < i+size; ++j) {
                std::cout << arr[j] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}