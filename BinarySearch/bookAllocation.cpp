#include <iostream>
#include <vector>

using namespace std;

int max_pages(const vector<int>& arr) {
    int maxi = arr[0];
    for (int elem : arr) maxi = max(maxi, elem);
    return maxi;
}

int total_pages(const vector<int>& arr) {
    int total = 0;
    for (int elem : arr) total += elem;
    return total;
}

int main() {
    int n;
    cout << "Size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Elements of array: ";
    for (int i = 0; i < n; ++i) cin >> arr[i]; 
    
    int k;
    cout << "No. of students: ";
    cin >> k;

    int low = max_pages(arr), high = total_pages(arr);
    int ans = -1;

    if (k > n) {
        cout << ans << endl;
        return 0;
    }

    while (low <= high) {
        // this is the max pages to be distributed among tht students
        int mid = low + (high - low) / 2; 

        // Distribution of pages
        int student = 1, pages = 0;

        for (int elem : arr) {
            pages += elem;

            if (pages > mid) {
                // start to allocate page to next student
                // change the student
                student++;
                pages = elem;
            }
        }

        // check whether the distribution has been successful or not (we check that using pages distributed among the students)
        if (student <= k) {
            // books distributed successfully
            // store in ans and look for smaller values (since we need minimum allocation)
            ans = mid;
            high = mid - 1;
        }
        else { // student > k
            // distribution isn't possible
            // look for higher pages (to make successful allocation)
            low = mid + 1;
        }
    }
    
    cout << ans << endl;

    return 0;
}