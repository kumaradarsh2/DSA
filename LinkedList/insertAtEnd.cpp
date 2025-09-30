#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node (int value) {
        data = value;
        next = NULL;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    Node* head = NULL;

    int index = 0;
    if (head == NULL) {
        head = new Node(arr[0]);
        index++;
    }

    Node* tail = head;
    while (index < n) {
        // create a node and store the location in tail->next
        tail -> next = new Node(arr[index++]);
        tail = tail -> next;
    }

    // print our ll
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << (temp -> next != NULL ? " -> " : "");
        temp = temp -> next;
    }
    cout << endl;

    return 0;
}