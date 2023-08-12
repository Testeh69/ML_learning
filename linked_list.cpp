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
        travelGetEndNodeLink()->link = newNode;

    }

    void insertAfter(int nodePosition,int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->link = travelGetNthPlusOnePositionNodeLink(nodePosition);
        travelGetNthPositionNodeLink(nodePosition)->link = newNode;

    }

    //delete method

    void popFront(){
        Node* pointerErase = head;
        head = head->link;
        delete pointerErase;
    }

    void popBack(){
        Node* pointerErase = head;
        Node* pointerCorrectif = head;
        pointerCorrectif = travelGetBeforeLastNodeLink();
        pointerErase = travelGetEndNodeLink();
        pointerCorrectif -> link = nullptr;
        delete pointerErase;
        
    }

    void removeNode(int node){
        Node* pointerErase = head;
        Node* pointerCorrectifBeforeTarget = head;
        Node* pointerCorrectifAfterTarget = head;
        pointerCorrectifBeforeTarget = travelGetNthPositionNodeLink(node-1);
        pointerCorrectifAfterTarget = travelGetNthPositionNodeLink(node+1);
        pointerErase = travelGetNthPositionNodeLink(node);
        delete pointerErase;
        pointerCorrectifBeforeTarget->link = pointerCorrectifAfterTarget;

    }


    //Traversal Method

    int getHead(){
        int dataReturn = head ->data;
        return dataReturn;
    }

    int getTail(){
        Node* pointerToGetData = head;
        pointerToGetData = travelGetEndNodeLink();
        int dataReturn = pointerToGetData->data;
        return dataReturn;
    }

    int getNode(int node){
        Node* pointerToGetData = head;
        pointerToGetData = travelGetNthPositionNodeLink(node);
        int dataReturn = pointerToGetData->data;
        return dataReturn;
    }

    private:
    
    Node* head;

    Node* travelGetBeforeLastNodeLink(){
        Node* travelPointer = head;
        while (travelPointer ->link->link){
            travelPointer = travelPointer->link;

        }
        return travelPointer;
    }

    Node* travelGetEndNodeLink(){
        Node* travelPointer = head;
        while (travelPointer && travelPointer->link){
            travelPointer = travelPointer->link;
        }
        return travelPointer; // Changer pour "return travelPointer->link;" pour obtenir le dernier nœud
    }

    Node* travelGetNthPositionNodeLink(int nthPosition){
        Node* travelPointer = head;
        for (int i= 0; i< nthPosition - 1; i++){
            travelPointer = travelPointer->link;
        };
        return travelPointer;
    }

    
    Node* travelGetNthPlusOnePositionNodeLink(int nthPosition){
        Node* travelPointer = head;
        for (int i= 0; i<= nthPosition - 1; i++){
            travelPointer = travelPointer->link;
        }
        return travelPointer;
    } 


};


int main(){
    LinkedList firstLinkedList;
    firstLinkedList.pushFront(3);
    firstLinkedList.pushBack(9);
    firstLinkedList.pushFront(10);
    firstLinkedList.pushBack(7);
    firstLinkedList.insertAfter(1, 2);
    firstLinkedList.pushBack(7);
    firstLinkedList.pushFront(77);
    firstLinkedList.pushFront(100);
    firstLinkedList.display();
    firstLinkedList.removeNode(4);
    firstLinkedList.display();
    int position = 5;
    cout <<"Head :"<< firstLinkedList.getHead() << endl;
    cout <<"Tail :"<< firstLinkedList.getTail() << endl;
    cout <<"Position ("<<position<<"): "<<firstLinkedList.getNode(position)<<endl;
    return 0;
}