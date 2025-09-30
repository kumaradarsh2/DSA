#include <iostream>

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

// printing our linked list
void printList(Node* temp) {
    // temp kya kar rha h?
    // address ko store kar rha h, linked list ki
    while (temp != NULL) {
        // print the data of the node
        cout << temp -> data << (temp -> next != NULL ? " -> " : "");

        // if (temp -> next != NULL) cout << " -> ";

        // move temp to next node
        temp = temp -> next; // ye next node ke address temp mei daal deta h
    }

    cout << endl;
}

int main() {
    Node* head = NULL;

    // we need to create a Node in heap memory and then point head to its location 
    head = new Node(20);

    // Now we have our linked list ready

    // let's insert a Node at the beginning
    Node* newNode = new Node(28);
    newNode -> next = head; // storing the base address of linked list into next (head)

    // Point head to newNode since its the new beginning
    head = newNode;

    // Printing our linked list 
    printList(head); // why pass head? cause it represents the base address of our linked list

    return 0;
}