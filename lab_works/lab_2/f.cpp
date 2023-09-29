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
    Node* head,* tail,* temp,* sl;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
        this->temp = NULL;
    }
    void InsertPosition(int data, int position, int n = 0){
        Node* newnode = new Node(data);
        if(position == 0){
            newnode->next = head;
            head = newnode;
            return;
        }
        temp = head;
        int cnt = 0;
        while(temp && cnt < position-1){
            temp = temp->next;
            cnt++;
        }
        if(temp){
        newnode->next = temp->next;
        temp->next = newnode;
        }

        
    }
    void SystemOut(){
        Node* current = head;
        while(current){
            cout << current->data << ' ';
            current = current->next;
        }
    }
};
int main(){
    int n, m, c, d;
    cin >> n;
    LinkedList l;
    for(int i = 0; i < n; ++i){
        cin >> m;
        l.InsertPosition(m, i);
    }
    cin >> c >> d;
    l.InsertPosition(c, d);
    l.SystemOut();
    
}