#include <iostream>
using namespace std;
struct Node{
    Node* next;
    string book;
    Node(string book){
        this->book = book;
        this->next = NULL;
    }
};
struct LinkedList{
    Node* head,* tail;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }
    int size = 0;
    void add_front(string book){
        Node* newnode = new Node(book);
        if(!head){
            head = tail = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
        size++;
    }
    void add_back(string book){
        Node* newnode = new Node(book);
        if(head){
        tail->next = newnode;
        tail = newnode;
        size++;
        }
        else if(!head){
            head = tail = newnode;
            size++;
        }
    }
    bool empty(){
        if(size == 0){
            return true;
        }
        else return false;
    }
    void erase_front(){
        if(size == 1){
            cout << head->book << endl;
            head = NULL;
            tail = NULL;
            size--;
        }
        else if(head){
            cout << head->book << endl;
            head = head->next;
            size--;
        }
    }
    void erase_back(){
        if(size == 1){
            cout << tail->book << endl;
            head = tail = NULL;
            size--;
        }
        else if(tail){
        Node* current = head;
        while(current->next->next){
            current = current->next;
        }
        cout << current->next->book << endl;
        current->next = NULL;
        size--;
        }
    }
    void front(){
        if(head){
            cout << head->book<< endl;
        }
    }
    void back(){
        if(tail){
            cout << tail->book << endl;
        }
    }
    void clear(){
        head = NULL;
        size = 0;
    }
   
    void SystemOut(){
        Node* current = head;
        while(current){
            cout << current->book << endl;;
            current = current->next;
        }

    }
};

int main(){
    string command;
    LinkedList l;
    while(true){
        cin >> command;
        string book;
        if(command=="add_front"){
            cin >> book;
            l.add_front(book);
            cout << "ok" << endl;
        }
        else if(command=="add_back"){
            cin >> book;
            l.add_back(book);
            cout << "ok" << endl;
        }
        else if(command=="erase_front"){
            if(l.empty()){
                cout << "error" << endl;
            }
            else{
                l.erase_front();
            }
        }
        else if(command=="erase_back"){
            if(l.empty()){
                cout << "error" << endl;
            }
            else{
                l.erase_back();
            }
        }
        else if(command=="front"){
            if(l.empty()){
                cout << "error" << endl;
            }
            else{
                l.front();
            }
        }
        else if(command =="back"){
            if(l.empty()){
                cout << "error" << endl;
            }
            else l.back();
        }
        else if(command=="clear"){
            l.clear();
            cout << "ok" << endl;
        }
        else if(command == "2"){
            l.SystemOut();
        }
        else if(command=="exit"){
            cout << "goodbye" << endl;
            break;
        }
    }
}