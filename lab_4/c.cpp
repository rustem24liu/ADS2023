#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *left, *right;
    int value;
    Node(int value = 0){
        this->value = value;
        right = left = NULL;
    }
    Node(int value, Node *right, Node *left){
        this->value = value;
        this->right = right;
        this->left = left;
    }
};

struct BST{
    Node *root = NULL;

    void insert(Node *current, int x){
        Node *next = NULL;
        if(x <= current->value){
            if(current->left == NULL){
                current->left = new Node(x);
                return;            
            }
            next = current->left;
        }
        else{
            if(current->right == NULL){
                current->right = new Node(x);
                return;
            }
            next = current->right;
        }

        insert(next, x);
    }
    void insert(int x){
        if(root == NULL){
            root = new Node(x);
        }
        else    
            insert(root, x);
    }

    Node * answer(int x){
        Node *current = root;
        while(current->value != x){
            if( x > current->value ) current = current->right;
            else current = current->left;
        }
        return current;
    }

    void preorder(Node *current){
        if(current == NULL) return;
        cout << current->value << " ";
        preorder(current->left);
        preorder(current->right);
    }




    void print(Node *current, int tab = 1){
        if(current != NULL){
            printf("[%d]\n", current->value);
        }
        else{
            puts("");
            return;
        }
    //  for the right
        for(int i = 0; i < tab; ++i) putchar('\t');

        printf("R ");
        
        print(current->right, tab+1);

    //  for the left
        for(int i = 0; i < tab; ++i) putchar('\t');

        printf("L ");

        print(current->left, tab+1);
    }

    void print(){
        print(root);
    }


};


int main(){
    
    BST tree;

    int n; cin >> n;

    for(int i = 0; i < n; ++i){
            int x; cin >> x;
            tree.insert(x);
    }
    int x; cin >> x;
    // tree.print();
    Node *f = tree.answer(x);
    tree.preorder(f);

}