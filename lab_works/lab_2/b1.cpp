#include <iostream>
using namespace std;
struct Node{
    string data;
    Node* next;
    Node(string data){
        this->next = NULL;
        this->data = data;
    }
};
struct LinkedList{
    Node* head,* tail;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }
    void Add(string data){
        Node* newnode = new Node(data);
        if(!head){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    void ShiftToRight(int n, int m){
        Node* temp = head;
        int cnt = 0;
        while(temp->next != NULL){
            temp = temp->next;
            cnt++;
        }
        temp->next = head;
        int jump = m-1;
        temp = head;
        while(jump){
            temp = temp->next;
            jump--;
        }
        head = temp->next;

        temp->next = NULL;
        
    }
    void SystemOut(){
        Node* current1 = head;
        while(current1){
            cout << current1->data << ' ';
            current1 = current1->next;
        }
    }
};
int main(){
    int n, m;
    cin >> n >> m;
    LinkedList l;
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        l.Add(s);
    }
    l.ShiftToRight(n, m);
    l.SystemOut();


}