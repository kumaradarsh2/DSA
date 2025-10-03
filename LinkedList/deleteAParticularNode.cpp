#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Create a linked list from a vector
Node* createLinkedList(const vector<int>& values) {
    if (values.empty()) return NULL;

    Node* head = new Node(values[0]);
    Node* current = head;

    for (size_t i = 1; i < values.size(); i++) {
        current->next = new Node(values[i]);
        current = current->next;
    }

    return head;
}


Node* deleteNode(Node* head, int pos) {
    if (head == NULL) return head;

    Node* curr = head;

    if (pos == 1) {
        // delete the first node
        head = curr->next;
        delete curr;
    }

    else {
        pos -= 2;
        while (pos--) {
            if (curr->next->next == NULL) return head; 
            else curr = curr->next;
        }

        Node* temp = curr->next;

        // Delete the node
        curr->next = temp->next;
        delete temp;
    }

    return head;
}

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << (head->next != NULL ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {2, 4, 6, 8};
    Node* head = createLinkedList(vals);

    printLL(head);

    int t;
    cin >> t;

    while (t--) {
    int pos;
    cout << "Delete(position): ";
    cin >> pos;

    
    head = deleteNode(head, pos);

    printLL(head);
    }

    return 0;
}