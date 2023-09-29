#include <iostream>
#include <map>
#include <cmath>
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
    Node* head, *tail;
    int size;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }
    void Insert(int value){
        size++;
        Node* newnode = new Node(value);
        if(!head){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = tail->next;
        }
    }
    void Modes(){
        Node* current = head;
        map <int, int> m;
        while(current){
            m[current->value]++;
            current = current->next;
        }
        map <int, int> :: reverse_iterator it;
        int maxi = 0;
        for(it = m.rbegin(); it!=m.rend(); ++it){
            if(it->second > maxi){
                maxi = it->second;
            }
        }
        for(it = m.rbegin(); it != m.rend(); it++){
            if(maxi==it->second){
                cout << it->first << ' ';
            }
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
    l.Modes();
    // l.print();
}