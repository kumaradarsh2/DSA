#include <iostream>
using namespace std;

void printArr(int arr[], int i, int N) {
    if (i == N) {
        cout << endl;
        return;
    } 

    cout << arr[i] << " ";
    printArr(arr, i+1, N);
}

int main() {
    int arr[] = {1,2,3,4,5};
    printArr(arr, 0, 5);

    return 0;
}