#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {3,7,9,11},
        {6,8,3,8},
        {4,11,12,5},
        {2,5,1,9}
    };

    // output: 3,7,9,11,8,3,8,6,4,11,12,5,9,1,2,5
    int row = matrix.size(), col = matrix[0].size();

    // har col pe jao and then col ke hisab se col ko print kro
    for (int i = 0; i < col; ++i) {
        if (i % 2 == 0) {//even wala col h
            for (int j = 0; j < row; ++j) cout << matrix[j][i] << " ";
        }
        else { // odd wala col h
            for (int j = row-1; j >= 0; --j) cout << matrix[j][i] << " ";
        }
    }
    cout << "\n";

    return 0;
}