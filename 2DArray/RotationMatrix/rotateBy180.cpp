#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// always pass the matrix 

void rotateBy90(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // take transpose and reverse each row
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        int left = 0, right = n-1;
        while (left < right) {
            swap(matrix[i][left], matrix[i][right]);
            left++, right--;
        }
    }
}

// Function to reverse rows
void reverseRows(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size();
    for (int i = 0; i < row; ++i) {
        int left = 0, right = col-1;
        while (left < right) {
            swap(matrix[i][left], matrix[i][right]);
            left++, right--;
        }
    }
}

// Function to reverse cols
void reverseCols(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size();
    for (int i = 0; i < col; ++i) {
        int left = 0, right = row-1;
        while (left < right) {
            swap(matrix[left][i], matrix[right][i]);
            left++, right--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Solution 1: Using O(2*n2) time and O(1) space
    // call rotateBy90 twice
/*
    rotateBy90(matrix);
    rotateBy90(matrix); 
*/

    // Solution 2: take top, bottom, left, right
    // do the swapping like in the solution
    // move left and right for each row, and then top and bottom
    // basically used two pointers kinda twice

    int top = 0, bottom = n-1;

    while (top < bottom) {
        int left = 0, right = n-1;
        while (left < right) {
            swap(matrix[top][left], matrix[top][right]);
            swap(matrix[bottom][left], matrix[bottom][right]);
            swap(matrix[top][left], matrix[bottom][left]);
            left++;
            swap(matrix[top][right], matrix[bottom][right]);
            right--;
        }
        top++, bottom--;
    }


    // Solution 3: Approach
    // Reverse rows and reverse cols

    //reverseRows(matrix);
    //reverseCols(matrix);


    // print the resulting matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}