#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int value){
        this->value = value;
        this->next = NULL;
    }
};
struct LinkedList
{
    Node* head,* tail;
    int size;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    // add function
    void add(int data, int position){
        Node* newnode = new Node(data);
        int cnt = 0;
        if(position == 0){
            newnode->next = head;
            head = newnode;
            size++;
        }
        else{
            Node* current = head;
            while(cnt < position-1){
                current = current->next;
                cnt++;
            }
            newnode->next = current->next;
            current->next = newnode;
            size++;
        }
    }
    // remove
    void remove(int position){
        if(position == 0){
            Node* curr = head;
            head = curr->next;
            size--;
        }
        else if(position == size-1){
            Node* current = head;
            while(current->next->next){
                current = current->next;
            }
            current->next = NULL;
            size--;
        }
        else{
            Node* current = head;
            int cnt = 0;
            while(cnt < position-1){
                current = current->next;
                cnt++;
            }
            current->next = current->next->next;
            size--;
        }
    }
    // checks if it's empty or not
    bool empty(){
        if(size == 0){
            return true;
        }
        else return false;
    }
    // reverse
    void reverse(){
        Node* prev = NULL;
        Node* next = NULL;
        Node* current = head;
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;

    }
    // replace
    void replace(int p1, int p2){
        if(p1 == 0){
            add(head->value, p2+1);
            remove(p1);
        }
        else{
            int cnt = 0;
            Node* prev = head;
            Node* current = prev->next;
            while(cnt < p1-1){
                current = current->next;
                prev = prev->next;
                cnt++;
            }
            remove(p1);
            add(current->value, p2);
        }
    }
    void cyclic_left(int x){
        Node* temp = head;
        Node* current = head;
        while(current->next){
            current = current->next;
        }
        current->next = head;
        int jump = x-1;
        current = head;
        while(jump){
            temp = temp->next;
            jump--;
        }
        head = temp->next;
        temp->next = NULL;
        
    }
    void cyclic_right(int x){
        Node* temp = head;
        int cnt = 0;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        int jump = size - x -1;
        temp = head;
        while(jump){
            temp = temp->next;
            jump--; 
        }
        head = temp->next;
        temp->next = NULL;
    }
    void print(){
        Node* current = head;
        while(current){
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};



int main(){
    LinkedList l;
    while(true){
        int n;
        cin >> n;
        if(n==1){
            int x, p;
            cin >> x >> p;
            l.add(x, p);
        }
        else if(n==2){
            int p;
            cin >> p;
            l.remove(p);
        }
        else if(n == 3){
            if(!l.empty()){
            l.print();
            }
            else cout << -1 << endl;
        }
        else if(n == 4){
            int p1, p2;
            cin >> p1 >> p2;
            l.replace(p1, p2);
        }
        else if(n == 5){
            l.reverse();
        }
        else if(n == 6){
            int x;
            cin >> x;
            l.cyclic_left(x);
        }
        else if(n == 7){
            int x;
            cin >> x;
            l.cyclic_right(x);
        }
        else if(n == 0){
            break;
        }
    }
}