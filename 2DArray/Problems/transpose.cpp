#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // the program takes an input matrix and converts it into its transpose without using extra space and thus loosing the original matrix in the process
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int> (col));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = i; j < col; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // printing the matrix
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}