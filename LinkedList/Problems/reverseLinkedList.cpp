#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Method 1: Store the value of nodes in array and then updating the values in reverse order
        /*
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        ListNode* curr = head;
        for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
            curr->val = *it;
            curr = curr->next;
        }
        */

        // Method2: Do it without using the extra space
        ListNode* prev = NULL; 
        ListNode* curr = head; 

        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev; // returning prev as new head
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Step 1: Create a sample linked list manually
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Step 2: Print original list
    cout << "Original list: ";
    printList(head);

    // Step 3: Reverse it using your function
    Solution obj;
    head = obj.reverseList(head);

    // Step 4: Print reversed list
    cout << "Reversed list: ";
    printList(head);

    return 0;
}