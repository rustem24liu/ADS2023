#include <iostream>
using namespace std;

struct Node{
    Node* next = NULL;
    string books;
    Node(string books = ""){
        this->books = books;
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
    void add_front(string books){
        Node* newnode = new Node(books);
        newnode->next = head;
        head = newnode;
        cout << "ok" << endl;
        size++;
    }  
    void add_back(string books){
        Node* newnode = new Node(books);
        Node* current = head;
        while(current->next){
            current = current->next;
        }
        current->next = newnode;
        cout << "ok" << endl;
        size++;
        
    } 
    void erase_front(){
        if(size == 1){
            cout << head->books << endl;
            head = NULL;
            size--;
        }
        else if(size != 0){
        Node* current = head;
        cout << current->books << endl;
        head = current->next;
        head->next = current->next->next;
        size--;
        }
        else if(size == 0){
            cout << "error" << endl;
        }
        
    }
    void erase_back(){
        if(size == 0){
            cout << "error" << endl;
        }
        else if(size == 1){
            cout << head->books << endl;
            head = NULL;
            size--;
        }
        else{
        Node* current = head;
        while(current->next){
            current = current->next;
        }
        cout << current->books << endl;
        current = head;
        while(current->next->next){
            current = current->next;
        }
        current->next = NULL;
        size--;
        }
    }
    void front(){
        if(size != 0){
        cout << head->books << endl;
        }
        else{
            cout << "error" << endl;
        }
    }
    void back(){
        if(size != 0){
        Node* current = head;
        while(current->next){
            current = current->next;
        }
        cout << current->books << endl;
        }
        else{
            cout << "error" << endl;
        }
    }
    void clear(){
        cout << "ok" << endl;
        head = NULL;
        size = 0;
    }
    void SystemOut(){
        Node* current = head;
        while(current){
            cout << current->books << ' ';
            current = current->next;
        }
        cout << size << endl;
    }
};
int main(){
    string command;

    LinkedList l;
    while(true){
        cin >> command;
        if(command == "add_front"){
            string books;
            cin >> books;
            l.add_front(books);
        }
        else if(command == "add_back"){
            string books;
            cin >> books;
            l.add_back(books);
        }
        else if(command == "erase_front"){
            l.erase_front();
        }
        else if(command == "erase_back"){
            l.erase_back();
        }
        else if(command == "front"){
            l.front();
        }
        else if(command == "back"){
            l.back();
        }
        else if(command == "clear"){
            l.clear();
        }
        else if(command == "print"){
            l.SystemOut();
        }
        else if(command == "exit"){
            cout << "goodbye" << endl;
            break;
        }
    }
}