#include <iostream>

using namespace std;
struct Node{
    Node* next;
    int data;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
struct LinkedList{
    Node* head,* tail;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }

    void Add(int data){
        Node* newnode = new Node(data);
        if(!head){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = tail->next;
        }
    }
    void findMaxSum(n, head){
        
    }
    
};


int main()
{
    
} 

