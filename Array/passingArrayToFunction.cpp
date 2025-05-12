#include <iostream>

void printArr(int a[], int size) {
    // Array is not passed but address of 1st element is passed
    std::cout << sizeof(a) << std::endl; // 8, since address (pointer) is passed which on 64-bit system occupies 8 bytes, on 32-bit system it would occupy 4 bytes

    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[5] = {1,2,3,4,5};

    std::cout << sizeof(arr) << std::endl;

    // Passing array to function
    printArr(arr, 5);

    return 0;
}