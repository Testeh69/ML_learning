#include <iostream>

using namespace std;

// Structure for a node in the linked list
struct Node {
    int data;    // Data stored in the node
    Node* link;  // Pointer to the next node in the list
};

void displayLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->link = nullptr;
    return newNode;
}

Node* createLinkedList() {
    Node* A = nullptr;
    int numberOfNodes;
    cout << "How many nodes should your linked list have?" << endl;
    cin >> numberOfNodes;

    Node* current = nullptr;
    for (int i = 0; i < numberOfNodes; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        Node* newNode = createNode(data);
        if (A == nullptr) {
            A = newNode;
            current = newNode;
        } else {
            current->link = newNode;
            current = newNode;
        }
    }
    return A;
}

int main() {
    Node* A = createLinkedList();
    displayLinkedList(A);

    // Clean up: Deallocate the dynamically allocated memory
    while (A != nullptr) {
        Node* temp = A;
        A = A->link;
        delete temp;
    }

    return 0;
}
