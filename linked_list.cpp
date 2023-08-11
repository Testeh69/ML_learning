#include <iostream>

using namespace std;

// Structure for a node in the linked list
struct Node {
    int data;    // Data stored in the node
    Node* link;  // Pointer to the next node in the list
};


class LinkedList
{
    public:
    //init method
    LinkedList(){
        head = nullptr;}

    void display(){
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->link;
        }
        cout << "NULL" << endl;
    }
    //Insertion Method
    void pushFront(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->link = head;
        head = newNode;
    }

    void pushBack(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->link = nullptr;
        travelGetEndNodLink()->link = newNode;

    }

    private:
    
    Node* head;

    Node* travelGetEndNodLink(){
    Node* travelPointer = head;
    while (travelPointer && travelPointer->link){
        travelPointer = travelPointer->link;
    }
    return travelPointer; // Changer pour "return travelPointer->link;" pour obtenir le dernier nœud
}


};


int main(){
    LinkedList firstLinkedList;
    firstLinkedList.pushFront(3);
    firstLinkedList.display();
    firstLinkedList.pushBack(9);
    firstLinkedList.display();

    return 0;
}