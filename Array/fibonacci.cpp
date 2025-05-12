#include <iostream>
#include <vector>

int main() {    
    // generate fibonacci series upto n terms
    int n;
    std::cin >> n;

    // Time complexity: O(N)
    // Space complexity: O(N)
    /*
    std::vector<int> arr(n);

    arr[0] = 0, arr[1] = 1; // default fibonacci values

    for (int i = 2; i < n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    // Printing the fibo series
    for (int elem : arr) std::cout << elem << " ";
    std::cout << std::endl;
    */
    /**************************************************************************************/
    
    // Optimization
    // In previous solution, we are taking O(N) space complexity
    // So we are going to optimize that
    int firstNum = 0, secondNum = 1;

    if (n > 0) std::cout << firstNum << " ";
    if (n > 1) std::cout << secondNum << " ";

    for (int i = 2; i < n; ++i) {
        int fibo = firstNum + secondNum;
        std::cout << fibo << " ";
        firstNum = secondNum;
        secondNum = fibo;
    }
    std::cout << std::endl;

    return 0;
}