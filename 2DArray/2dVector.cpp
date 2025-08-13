#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int row {}, col {};
    cin >> row >> col;

    vector<vector<int>> matrix(row, vector<int> (col));
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";       
        }
        cout << "\n";
    }

    return 0;
}
