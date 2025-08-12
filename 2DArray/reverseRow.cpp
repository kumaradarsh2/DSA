#include <iostream>
#include <algorithm>

void printMatrix(int arr[][4], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int arr[3][4] = {
        {2,3,4,5},
        {1,2,6,8},
        {4,9,3,2}
    };

    int row = 3, col = 4;
    // reverse each row of matrix

    // Approach: Interate over each row and using two pointers reverse the row

    printMatrix(arr, row, col);
    
    for (int i = 0; i < row; ++i) {
        int left = 0, right = col-1; 

        while (left < right) {
            std::swap(arr[i][left], arr[i][right]);
            left++, right--;
        }
    }

    printMatrix(arr, row, col);

    return 0;
}