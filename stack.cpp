#include <iostream>

struct Node{
    int data;
    Node* link;
};


class Stack
{
private:
    Node* head;


public:
//constructor method
    Stack(int data)
    {
    head = new Node();
    head->data = data;
    head->link = nullptr;
    };
// Add and remove methods

    void push(int data){

        Node* newHead = new Node;
        newHead->data = data;
        newHead->link = head;
        head = newHead;
    }


    int pop(){
        if (isEmpty() == false){
        int firstData = head->data;
        Node* getNodeErase = head;
        head = head->link;
        delete getNodeErase;
        return firstData;
        }
        return 0;
    }


    int peek(){
        int firstData = head->data;
        return firstData;
    }


//miscellannous methods


 
    void clear() {
     while (head) {
        Node* deleteNode = head;
        head = head->link;
        delete deleteNode;
    }
    // After clearing, set head to nullptr
    head = nullptr;
    }

    void display() {
        Node* current = head; // Make a copy of head
        while (current) {
            std::cout << current->data << "->";
            current = current->link;
        }
        std::cout << "Null" << std::endl;
    }


    bool isEmpty(){
        return head==nullptr;

    }

    int getSize(){
        int size = 0;
        Node* pointerToSize = head;
        while(pointerToSize){
            pointerToSize = pointerToSize->link;
            size++;
        }
        return size;
    }
    
    void initialize(int data){
        if (head != nullptr){
            clear();
        }
        head = new Node;
        head->data = data;
        head->link = nullptr;
    }





};





int main(){
    Stack firstStack(3);
    firstStack.push(6);
    firstStack.push(13);
    std::cout<<firstStack.peek()<<std::endl;
    std::cout<<firstStack.pop()<<std::endl;
    std::cout<<firstStack.isEmpty()<<std::endl;
    std::cout<<"Size ->"<<firstStack.getSize()<<std::endl;
    firstStack.clear();
    std::cout<<"display"<<std::endl;
    firstStack.display();
    firstStack.initialize(45);
    firstStack.push(33);
    firstStack.push(13);
    firstStack.push(13);
    std::cout<<"Size ->"<<firstStack.getSize()<<std::endl;
    std::cout<<firstStack.isEmpty()<<std::endl;
    firstStack.display();


}

