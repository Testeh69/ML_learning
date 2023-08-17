# include <iostream>

using namespace std;


struct Node{
    int data; //Data stored in the node
    Node* link_prev; // pointer to the previous node
    Node* link_next; //pointer to the next node
};


class DoublyLinkedList{


    public:
    //Init method
    DoublyLinkedList(){
        head = nullptr;
    }


    void display(){
        Node* current = head;
        while (current){
            cout << current->data<< "->";
            current = current->link_next;
        }
        cout << "NULL" << endl;
    }

    //Insertion Method

    void pushFront(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->link_next = head;
        newNode->link_prev = nullptr;
        head = newNode;
    }

    void pushBack(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->link_next = nullptr;
    newNode->link_prev = travelGetEndNodeLink();
    travelGetEndNodeLink()->link_next = newNode;
    }

    void insertAfter(int nodePosition, int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->link_next = travelGetNthNodeLink(nodePosition);
        newNode->link_prev = travelGetNthNodeLink(nodePosition-1);
        travelGetNthNodeLink(nodePosition)->link_next = newNode;
        travelGetNthNodeLink(nodePosition+1)->link_prev = newNode;

    }



    private:

    Node* head;

    Node* travelGetEndNodeLink(){
        Node* travelPointer = head;
        while (travelPointer && travelPointer->link_next){
            travelPointer = travelPointer->link_next;
        }
        return travelPointer;

    }

    Node* travelGetNthNodeLink(int positionNode){
        Node* travelPointer = head;
        int compteurPas = 0;
        while (compteurPas != positionNode){
            compteurPas ++;
            travelPointer = travelPointer->link_next;
        }
        return travelPointer;

    }
};


int main(){
    DoublyLinkedList firstDoublyLinkedList;
    firstDoublyLinkedList.pushFront(3);
    firstDoublyLinkedList.pushBack(5);
    firstDoublyLinkedList.pushFront(100);
    firstDoublyLinkedList.pushBack(77);
    firstDoublyLinkedList.insertAfter(2,27);
    firstDoublyLinkedList.display();
    return 0;
}