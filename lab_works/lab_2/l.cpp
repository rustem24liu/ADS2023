#include <iostream>
#include <cmath>
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
    Node* head,* tail;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }

    void Add(int data){
        Node* newnode = new Node(data);
        if(!head){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = tail->next;
        }
    }
    int index = 0;
    int Min = 2147483647;
    void findMin(int size){
        Node* current = head;
        for(int i = 0; i < size; ++i){
            if(current->data < Min){
                Min = current->data;
                index = i;
            }
            current = current->next;
        }
        // cout << index << endl;
    }
    int firstsum = 0;
    int secondsum = 0;
    int sum = 0;
    void firstsum1(int size){
        Node* current = head;
        int cnt = 0;
        if(index == 0){
            firstsum = head->data;
        }
        while(cnt < index){
            firstsum+=current->data;
            // cout << current->data << endl;
            current = current->next;
            cnt++;
        }
        int cnt2 = index+1;
        while(cnt2 <= size){
            secondsum+=current->data;
            cout << current->data << endl;
            current = current->next;
            cnt2++;
        }
        secondsum -= Min;

    }
    void allsum(){
        Node* current = head;
        while(current){
            sum+=current->data;
            current = current->next;            
        }
    }
    void check(){
        // int max1 = max(firstsum, secondsum);
        // int maxi = max(max1, sum);
        // cout << maxi;
        cout << firstsum <<" " <<  secondsum << " " <<sum<< endl;;
        cout << Min << ' ' << index <<  endl;
    }
    
};


int main()
{   
    LinkedList l;
    int n, m; cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> m;
        l.Add(m);
    }
    l.findMin(n);
    l.firstsum1(n);
    l.allsum();
    l.check();

} 

