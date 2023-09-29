#include <bits/stdc++.h>
using namespace std;
struct node{ 
    int value;
    node* next;
    node(int value){ // like function
        this->value = value; // we initialize 
        this->next = NULL;
    }
    
};

struct LinkedList{
    int size = 0;
    node * head, * tail; // аттрибуты нода 
    LinkedList(){ // тоже функция
        this->head = NULL;
        this->tail = NULL;
    }

    void add(int value){ // функция косу ушын
        size++;
        node* newnode = new node(value);
        if(!head){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    void print(){
        node * current = head;
        while(current != 0){
            cout << current->value << ' ';
            current = current->next;
        }
    }
    int answer(int m){
        node * current = head;
        int ans = 0;
        int mini = INT_MAX;
        for(int i = 0; i < size; ++i){
            if(abs(m-current->value) < mini){
                mini = abs(current->value-m);
                ans = i;
            }
            current = current->next;
        }
        return ans;

    }
};
int main(){
    int n, c;
    cin >> n;
    LinkedList l;
    for(int i = 0; i <  n; ++i){
        cin >> c;
        l.add(c);
    }
    int m; cin >> m;
    cout << l.answer(m);
}