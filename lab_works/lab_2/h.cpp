#include <iostream>
#include <cmath>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
struct LinkedList{
    Node* head, *tail, *temp;
    int size = 0;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
        this->temp = NULL;
        this->size = 0;
    }
    void Insert(int data, int position){
        Node* newnode = new Node(data);
        if(position==0){
            newnode->next = head;
            head = newnode;
            size++;
        }
        else{
        int cnt = 0;
        temp = head;
        while(cnt < position-1){
            temp = temp->next;
            cnt++;
        } 
        newnode->next = temp->next;
        temp->next = newnode;
        size++;
        }
    }
    void Delete(int position){
        Node* current = head;
        Node* last = head;
        if(position == 0){
            head = current->next;
            head->next = last->next->next;
            size--;
        }
        int cnt = 0;
        while(cnt < position-1){
            current = current->next;
            cnt++;
        }
        last = current->next;
        current->next = last->next;
        last = current->next;
        size--;
    }
    void Print(){
        Node* curr = head;
        while(curr){
            cout << curr->data << ' ';
            curr = curr->next;
        }
    }
    void Replace(int p1, int p2){
    Node * node = head;
    // Node* curr1 = haed
    if(p1 != 0){
        Node * cur = head;
        while (--p1) cur = cur -> next;
        node = cur -> next;
        cur -> next = cur -> next -> next;
    }else{
        node = head;
        head = head -> next;
        }
    Insert(node->data, p2);
    }
        
    void Reverse(){
        Node* next,* prev = NULL;
        Node* current = head;
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void Cyclic_left(int x){
        Node* current = head;
        Node* second = head->next;
        while(current->next){
            current = current->next;
        }
        current->next = head;
        current->next->next = NULL;
        head = second;
        return;
    }
    void Cyclic_right(int x){
        Node* current = head;
        int cnt = 0;
        while(current->next != NULL){
            current = current->next;
            cnt++;
        }
        current->next = head;
        int jump = size-x-1;
        current = head;
        while(jump){
            current = current->next;
            jump--;
        }
        head = current->next;
        current->next = NULL;
        // cout << size;
    }

    
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int command;
    LinkedList l;
    while(true){
        cin >> command;
        if(command == 1){
            int x, p; cin >> x >> p;
            l.Insert(x, p);
        }
        else if(command == 2){
            int p; cin >> p;
            l.Delete(p);
        }
        else if(command == 3){
            l.Print();
        }
        else if(command == 4){
            int p1, p2; cin >> p1 >> p2;
            l.Replace(p1, p2);
        }
        else if(command == 5){
            l.Reverse();
        }
        else if(command == 6){
            int x; cin >> x;
            while(x){
            l.Cyclic_left(x);
            x--;
            }
        }
        else if(command == 7){
            int x; cin >> x;
            l.Cyclic_right(x);
        }
        else if(command == 0){
            break;
        }

    }
} // namespace std;
