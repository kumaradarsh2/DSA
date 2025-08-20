#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int> (col));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    // we have to search for a target in the matrix

    // Sol 1: interate in each row and use binary search
    // Time complexity: O(N + logN) i.e. in worst we gonna traverse all the rows and then apply binary search in that row
    // Space complexity: O(1) since no extra space is used
    bool found = false;
/*
    for (int i = 0; i < row; ++i) {
        int low = 0, high = col-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[i][mid] == target) {
                found = true;
                cout << "row: " << i << " col: " << mid << endl;
                break;
            }
            else if (matrix[i][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
    }
*/

    // Sol 2: instead of using outer for loop to iterate all rows, we can use binary search to find row itself and use binary search again to find element in that row

/*
    int top = 0, bottom = row - 1;

    while (top <= bottom) {
        int midIndex = top + (bottom - top) / 2;
        int low = 0, high = col-1;

        if (target >= matrix[midIndex][low] && target <= matrix[midIndex][high]) {
            // Target might be present here
            // binary search to find target index
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (matrix[midIndex][mid] == target) {
                    found = true;
                    cout << "Row: " << midIndex << " Col: " << mid << endl;
                    break;
                }
                else if ( matrix[midIndex][mid] < target) low = mid + 1;
                else high = mid - 1;
            }
            // we break after entering if block
            break;
        }
        else if (target > matrix[midIndex][high]) top = midIndex + 1; // target might be present in next rows
        else bottom = midIndex - 1; // target might be present in previous rows
    }

    if (found) cout << "found\n";
    else cout << "Not found\n";
*/

    // Solution 3: since in memory, we know data is stored in row major form, we can use that to access the element
    
    int low = 0, high = row*col-1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // find the element using row major property
        int row_index = mid / col;
        int col_index = mid % col;
        if (matrix[row_index][col_index] == target) {
            found = true;
            cout << "found" << endl;
            cout << "Row: " << row_index << " Col: " << col_index << endl;
            break;
        }
        else if (matrix[row_index][col_index] < target) low = mid + 1;
        else high = mid - 1; 
    }

    if (!found) cout << "Not found" << endl;

    return 0;
}