// rotate by 90 degrees anti-clockwise
#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    // sol 1: rotate 90 degrees thrice
    // Approach: take transpose and reverse each col
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    // transpose
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse each row
    // I can use two pointer approach here too
    int top = 0, bottom = n-1;
    while (top < bottom) {
        int left = 0, right = n-1;
        while (left < right) {
            swap(matrix[top][left], matrix[bottom][left]);
            swap(matrix[top][right], matrix[bottom][right]);
            left++, right--;
        }
        top++, bottom--;
    }   

    // print the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}