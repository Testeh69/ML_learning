#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* linkRight;
    Node* linkLeft;
    Node(int val) : data(val), linkRight(nullptr), linkLeft(nullptr) {}
};


class binaryTree{
    public:
    //Constructor method
    binaryTree(int data){
        head = new Node(data);

    }

    bool search(int data){
        Node* current = head;
        bool verdict = search(data,current);
        return verdict;
    }

    //Display method
    void display(){
      Node* current = head;
      display(current);
      cout<<"Null";
      }
    
    //add a node
    void insert(int data){
        Node* travel = head;
        insert(data,travel);

    }

    private:
    Node* head;
    Node* travel;

    bool search(int data, Node* travel){
        if (travel == nullptr){
            return false;
        }
        if (travel->data == data){
            return true;
        }

        if (travel->data < data){
            return search(data, travel->linkRight);
        }
        else{
            return search(data, travel->linkLeft);
        }

    }

    //Insert node in the binary tree 
    void insert(int data, Node* travel){
       
        if (travel->data> data){
            if (travel->linkLeft){
            insert(data, travel->linkLeft);
            }
            else{
                travel->linkLeft = new Node(data);
            }

        }
        else if (travel->data <data){
            if (travel -> linkRight){
            insert(data,travel->linkRight);
            }
            else{
                travel->linkRight = new Node(data);
            }
        }
        else {
            cout<<"The same value is in the binary tree -> "<<data<<endl;
        }

    }

     void display(Node* travel){
        if(travel){
            display(travel->linkLeft);
            cout<<travel->data<<"->";
            display(travel->linkRight);
        }}
};

    

int main(){
    binaryTree firstTree(3);
    firstTree.insert(2);
    cout<<"search"<<firstTree.search(5)<<endl;

    firstTree.insert(5);
    firstTree.insert(4);
    firstTree.insert(6);
    cout<<"search"<<firstTree.search(5)<<endl;

    firstTree.insert(4);
    firstTree.insert(-1);

    firstTree.display();
    return 0;
}