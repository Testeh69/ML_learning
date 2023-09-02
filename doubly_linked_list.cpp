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
        Node* newNode = new Node();//Crée un nouveau bloc mémoire qui lie deux pointer avec une case int
        Node* saveNode = travelGetNthNodeLink(nodePosition+1);
        newNode->data = data; // Attribue à la case int une valeur int data
        travelGetNthNodeLink(nodePosition+1)->link_prev = newNode;
        newNode->link_next = saveNode;
        travelGetNthNodeLink(nodePosition)->link_next = newNode;
        newNode->link_prev = travelGetNthNodeLink(nodePosition-1);
        

    }

    //Delete Method


    int popFront(){
        Node* currentNode = head;
        int dataGet = currentNode->data;
        head = head->link_next;
        head->link_prev = nullptr;
        delete currentNode;
        return dataGet ;  
    }

    int popBack(){
        Node* currentNode = travelGetEndNodeLink();
        Node* getNodeBeforeEnd = travelGetEndNodeLink()->link_prev;
        getNodeBeforeEnd->link_next = nullptr;
        int dataGet = currentNode->data;
        delete currentNode;
        return dataGet;
    }

    int removeNode(int node){
        Node* pointerGetNodeBefore = travelGetNthNodeLink(node-1);
        Node* pointerGetNodeAfter = travelGetNthNodeLink(node+1);
        Node* pointerGetNode = travelGetNthNodeLink(node);
        int dataGet = pointerGetNode->data;
        delete pointerGetNode;
        pointerGetNodeAfter ->link_prev = pointerGetNodeBefore;
        pointerGetNodeBefore ->link_next = pointerGetNodeAfter;
        return dataGet;

    }

    //Traversal method

    int getHead(){
        return head->data;
    }

    int getTail(){
        Node* pointerTravel = travelGetEndNodeLink();
        return pointerTravel->data;
    }

    int getNode(int nodePosition){
        Node* pointerTravel = travelGetNthNodeLink(nodePosition);
        return pointerTravel->data;
    }

    //search and access method

    bool isEmpty(){
        if (head == nullptr){
            cout<<"True"<<endl;
            return true;
        }
        else{
            cout<<"False"<<endl;
            return false;
        }
    }

    int size(){
        Node* pointerTravel = head;
        int length = 1;
        while (pointerTravel->link_next){
            pointerTravel = pointerTravel->link_next;
            length++;
        }
        return length;
    }


    bool contains(int data){
        Node* pointerTravel = head;
        bool verdict = false;
        if (pointerTravel->data ==data){
            verdict = true;
        }
        while (pointerTravel->link_next){
            pointerTravel = pointerTravel->link_next;
            if (pointerTravel->data == data){
                verdict = true;
            }
        }

        switch (verdict){
            case true:
                cout<<"true"<<endl;
                break;
            case false:
                cout<<"false"<<endl;
        }
        return verdict;
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
        for (int compteurPas = 1; compteurPas < positionNode;compteurPas++){
            travelPointer = travelPointer->link_next;
        }
        return travelPointer;

    }

};


int main(){
    DoublyLinkedList firstDoublyLinkedList;
    cout<<"Return function isEmpty: " << firstDoublyLinkedList.isEmpty()<<endl;
    firstDoublyLinkedList.pushFront(3);
    firstDoublyLinkedList.pushBack(5);
    firstDoublyLinkedList.pushBack(10);
    firstDoublyLinkedList.pushBack(7);
    firstDoublyLinkedList.insertAfter(2,11);
    firstDoublyLinkedList.pushFront(77);
    firstDoublyLinkedList.display();

    cout<<"Return function size: " << firstDoublyLinkedList.size()<<endl;
    cout<<"Return function isEmpty: " << firstDoublyLinkedList.isEmpty()<<endl;
    cout<<"Return function contains: " << firstDoublyLinkedList.contains(77)<<endl;
    firstDoublyLinkedList.display();


   
    return 0;
}