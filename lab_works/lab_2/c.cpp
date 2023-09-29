#include <iostream>
using namespace std;
struct Node{
    Node* next;
    int value;
    Node(int value){
        this->value = value;
        this->next = NULL;
    }
};
struct LinkedList{
    Node* head,*tail;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }
    void Insert(int value){
        Node* newnode = new Node(value);
        if(!head){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    void SystemOut(){
        int i = 0;
        Node* current = head;
        while(current){
            i++;
            if(i%2 != 0){
                cout << current->value << ' ';
            }
            current = current->next;
        }
    }
    void DeleteSecond(){
        Node* odd = head;
        Node* even = head->next;
        if(head == NULL){
            return;
        }
        if(even->next==NULL){
            odd->next = NULL;
        }
        else{
            while(even != NULL && even->next != NULL){
                odd->next = even->next;
                odd = odd->next;
                even->next = odd->next;
                even = even->next;
            }
            odd->next = NULL;

        }
    }
};
int main(){
    int n; cin >> n;
    LinkedList l;
    for(int i = 0; i < n; ++i){
        int c; cin >> c;
        l.Insert(c);
    }
    // l.DeleteSecond();
    l.SystemOut();
}