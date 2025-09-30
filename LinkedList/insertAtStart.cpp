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

void insertAtEnd(Node* temp, int value) {
    while (temp -> next != NULL) {
        temp = temp -> next;
    }

    // temp stores the last node's address now
    // create a new node and insert it
    Node* newNode = new Node(value);
    temp -> next = newNode;
}

int main() {
    // Read an array from STDIN and print an LL of the elements, inserting each elements to the beginning of the LL
    int n;
    cout << "Size: ";
    cin >> n;

    cout << "Input: ";
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    Node* head = NULL;

    for (int elem : arr) {
        if (head == NULL) {
            // if ll is empty, then create the first node
            head = new Node(elem);
        }
        else {
            // first create a new node
            Node* newNode = new Node(elem);
            newNode -> next = head;
            head = newNode;
        }
    }

    // print the ll
    Node* temp = head;

    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp -> data << (temp -> next != NULL ? " -> " : "");
        temp = temp -> next;
    }
    cout << endl;

    // Now insert a node at the end
    int val;
    cout << "Value: ";
    cin >> val;
    insertAtEnd(head, val);

    // Print again:
    temp = head;
    cout << "New Linked List: ";
    while (temp != NULL) {
        cout << temp -> data << (temp -> next != NULL ? " -> " : "");
        temp = temp -> next;
    }
    cout << endl;

    return 0;
}