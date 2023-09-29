#include <iostream>
using namespace std;
struct Node{
    Node* next;
    string name;
    Node(string name){
        this->name = name;
        this->next = NULL;
    }
};
struct LinkedList{
    Node* head, *tail, *current;
    int cnt = 0;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
        this->current = NULL;
    }
    void add(string name){
        Node* newnode = new Node(name);
        
        if(!head){
            head = tail = current = newnode;
            cnt++;
        }
        else{
            if(name != current->name){
                cnt++;
                tail->next = newnode;
                tail = tail->next;
                current = current->next;
            }
            else{
 
            }
        }
    }
    void reverse(){
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(current){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                // cout << prev->name << " ";
            }
            head = prev;
    }
    void SystemOut(){
        Node* temp = head;
        cout <<"All in all: " << cnt << endl;
        cout <<"Students:" << endl;   
        while(temp != NULL){
            cout << temp->name << endl;
            temp = temp->next;
        }
    }
};
int main(){
    int n; cin >> n;
    LinkedList l;   
    for(int i = 0; i < n;++i){
        string name; cin >> name;
        l.add(name);
    }
    l.reverse();
    l.SystemOut();
}