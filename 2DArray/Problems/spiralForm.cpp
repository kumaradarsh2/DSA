#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Solve spiral matrix problem 
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int> (col));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> matrix[i][j];
        }
    }

    // int row = matrix.size(), col = matrix[0].size();

    int top = 0, right = col-1, left = 0, bottom = row-1;

    while (top <= bottom && left <= right) {
        // when on top, print from left to right
        for (int i = left; i <= right; ++i) cout << matrix[top][i] << " ";
        top++; // moves down

        // when on right, print from top to bottom
        for (int i = top; i <= bottom; ++i) cout << matrix[i][right] << " ";
        right--; // moves left

        // when on bottom, print from right to left
        if (top <= bottom) { // check the boundary condition here
            for (int i = right; i >= left; --i) cout << matrix[bottom][i] << " ";
            bottom--; // moves up
        }

        // when on left, print from bottom to top
        if (left <= right) { // check the condition here too
            for (int i = bottom; i >= top; --i) cout << matrix[i][left] << " ";
            left++; // moves right
        }
    }

    cout << "\n";

    return 0;
}