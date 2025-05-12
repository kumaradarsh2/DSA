#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {2,3,4,7,11};

    // Time complexity: O(N + 1000 + k) = O(N)
    // Space complexity: O(1000+k)

    int k;
    std::cin >> k;

    std::vector<bool> freqArr(1000+k);
    for (int elem : arr) {
        freqArr[elem-1] = 1;
    }

    // Printing the array
    // for (int elem : freqArr) std::cout << elem << " ";
    // std::cout << std::endl;

    int count = 0;
    int i;
    // Finding missing elements
    for (i = 0; i < freqArr.size(); ++i) {
        if (freqArr[i] == 0) {
            count++;
            if (count == k) break;
        }
    }

    // i+1 cause frequency array has been mapped like: 1 --> 0 so we increase it by one to get the mapped number
    std::cout << "Missing element: " << i+1 << std::endl;

    return 0;
}