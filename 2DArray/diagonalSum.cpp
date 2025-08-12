#include <iostream>

using namespace std;

int main() {
    // Must be a square matrix if we wanna print the digonal sum
    int arr[4][4] = {5,8,3,9,6,2,8,4,5,3,2,2,2,8,1,9};
   
    // This is how we calculate size of matrix (similar to array)
    // cout << sizeof(arr)/sizeof(int) << endl;
    
    int sumDiag1 = 0, sumDiag2 = 0;
   
    // To get the sum of first digonal (row == col) i.e. i == j
    
    // To get the sum of second digonal
    /*
        Row varies as => 0, 1, 2, 3 
        Col varies as => 3, 2, 1, 0

        this means their sum is 2 in all these case 
    */
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == j) sumDiag1 += arr[i][j];
            if (i + j == 3) sumDiag2 += arr[i][j];
        }
    }

    cout << sumDiag1 << endl;
    cout << sumDiag2 << endl;

    return 0;
}