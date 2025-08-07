#include <iostream>

using namespace std;

/*
I understood that:
Let's start with 2nd element, it can go either one step back or 0 step i.e. it doesn't move. so on an average: 1/2 * (0+1) = 1/2 * 1
For 3rd element: it can move back, 2,1,0 steps so on an average: 
1/3 * (0+1+2) = 1/2 * 2
for 4th element: 3,2,1,0 => 1/4 * (0+1+2+3)... = 1/2 * 3
....
for n-1th element: n-2,n-3,n-4,...,2,1,0 => 1/n-1 * (0+1 + 2 + 3 + ... + n-2) = 1/2 * (n-2)

adding all the cases: 1/2 * (1+2+3+...+n-2) = 1/4 * (n-1)(n-2) 
= O(n2)

correct or  no? got this after understanding how an element can move left..or it doesn't move at all. and got this down.
*/

int main() {
    int arr[] = {5,4,3,2,1};
    
    // we need to sort this using bubble sort
    int n = sizeof(arr)/sizeof(int);

    // Insertion sort (sorting in each pass or round)
    int swap_count = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0; --j) {
            if (arr[j] < arr[j-1]) {
                cout << "swapped" << endl;
                swap_count++;
                swap(arr[j], arr[j-1]);
            } else {
                // this is the optimization we have made
               break;  
            }
        }
    }
    cout << "total swaps made: " << swap_count << endl;
    for (int elem : arr) cout << elem << " ";
    cout << endl;

   return 0;
}