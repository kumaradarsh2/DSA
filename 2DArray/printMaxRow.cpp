#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// We have to print the row with max sum
int printMaxRow(int arr[][4], int row, int col) {
    int maxSum = INT_MIN;
    int maxRow = 0; 

    for (int i = 0; i < row; ++i) {
        int sum = 0;
        for (int j = 0; j < col; ++j) {
            sum += arr[i][j];
        }
        if (maxSum < sum) {
            maxSum = sum;
            // update the maxRow here
            maxRow = i;
        }
    }
    return maxRow;
}

int main() {
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};

    int result = printMaxRow(arr, 3, 4);

    cout << result << endl;

    return 0;
}