#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int low, int high) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) 
        return binarySearch(arr, target, mid+1, high);
    else 
        return binarySearch(arr, target, low, mid-1);
}

int main() {
    int arr[] = {3, 8, 11, 15, 20, 22};
    int n = sizeof(arr)/sizeof(int);
    int target = 20;

    int index = binarySearch(arr, target, 0, n-1);
    cout << index << endl;

    return 0;
}