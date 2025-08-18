// Given a matrix, rotate it by 90 degrees

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Solution 1: using O(n2) time and O(n2) space
    // Approach: create A rotated matrix rotatedMatrix with same size of given matrix
    //           and from the patterns insert the elements

    // Solution 2: do it in O(1) space
    // Approach: take transpose + reverse each row 
    // why? 
    // Because by looking closely the row of rotated matrix is actually col of given matrix in reverse order
    // Also note: to use this method, the matrix must be sqaure to do transpose in place
    int n;

    cin >> n;

    vector<vector<int>> matrix(n, vector<int> (n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // take transpose of this matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // now iterate over each row and reverse by two pointer approach
    for (int i = 0; i < n; ++i) {
        int left = 0, right = n-1;
        while (left < right) {
            swap(matrix[i][left], matrix[i][right]);
            left++, right--;
        }
    }


    // print the resulting matrix
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}