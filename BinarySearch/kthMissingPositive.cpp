#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = {2,3,4,7,11,12};

    int k;
    std::cin >> k;

    // Method 1:

    // Time complexity: O(1000 + k + N) = O(M + N)
    // Space complexity: O(1000+k) = O(M) 
/*

    std::vector<bool> freqArr(1000+k);
    for (int elem : arr) {
        freqArr[elem-1] = 1;
    }

    // Printing the array
    // for (int elem : freqArr) std::cout << elem << " ";
    // std::cout << std::endl;

    int count = 0;
    int i;
    // Finding missing elements
    for (i = 0; i < freqArr.size(); ++i) {
        if (freqArr[i] == 0) {
            count++;
            if (count == k) break;
        }
    }

    // i+1 cause frequency array has been mapped like: 1 --> 0 so we increase it by one to get the mapped number
    std::cout << "Missing element: " << i+1 << std::endl;
*/

/****************************************************************************************************/

    // Method 2: Optimization
    // Time complexity: O(N + log N)
    // Space complexity: O(N) since we are creating a missingArr 

/*
    std::vector<int> missingArr;
    for (int i = 0; i < arr.size(); ++i) {
        int missingElem = arr[i] - i - 1;
        missingArr.push_back(missingElem);
    }   

    // Now find the correct position of kth missing number
    int low = 0, high = missingArr.size() - 1;

    int index = high; // default index
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (missingArr[mid] >= k) {
            index = mid;
            // Search to the left
            high = mid - 1;
        }
        else { // missingArr[mid] < k
            low = mid + 1;
        }
    }

   
*/
/**************************************************************************************************/

    // Method 3: Optimizing Time and Space (taking no extra space)
    // Time complexity: O(log N)
    // Space complexity: O(1) since we are not taking any extra space

    int low = 0, high = arr.size()-1;
    int index = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid]-mid-1 >= k) {
            index = mid;
            high = mid - 1;
        }
        else { // arr[mid]-mid-1 < k
            low = mid + 1;
        }
    }

    std::cout << index + k << std::endl;

    // How did we get index + k ?
    /*
        Let's take an example:
        int arr[] = {2,3,4,7,11,12};

        Now, 11 has 6 numbers missing before it, 7 has 3 numbers missing before it
        
        Formula for missing numbers before arr[index] is `arr[index]-index-1`

        kth missing number from arr[index]

        11 - 1 = 10 (6th missing number)
        11 - 2 = 9 (5th missing number)
        11 - 3 = 8 (4th missing number)

        In General, kth missing number: 11 - (6-k+1) 

        General Formula: arr[index] - (missing numbers before arr[index] - k + 1)
                    =>   arr[index] - (arr[index] - index - 1 - k + 1) 
                    =>   index + k
    */

    return 0;
}