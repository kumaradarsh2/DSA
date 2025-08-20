#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int> (cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) cin >> matrix[i][j];
    }

    int target;
    cin >> target;

    int top = 0, right = cols-1;

    bool found = false;

    while (top < rows && right >= 0) {
        if (matrix[top][right] == target) {
            found = true;
            break;
        }
        else if (matrix[top][right] < target) top++;
        else right--;
    }
    
    if (found) cout << "Target found\n";
    else cout << "Target not found\n";

    }
    return 0;
}