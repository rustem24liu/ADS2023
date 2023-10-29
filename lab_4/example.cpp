#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *left, *right;
    int value;
    Node(int value = 0){
        left = right = NULL;
        this->value = value;
    }
    Node(int value, Node *right, Node *left){
        this->left = left;
        this->right = right;
        this->value = value;
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

    Node *find(Node *current, int x){
        if(x == current->value){
            return current;
        }
        if(x > current->value){
            return current->right == NULL ? NULL : find(current->right, x);
        }
        else{
            return current->left == NULL ? NULL : find(current->left, x);   
        }
    }

    Node *find(int x){
        return find(root, x);
    }

    void print(Node *current, int tab = 1){
        if(current != NULL){
            printf("[%d]\n", current->value);
        }
        else{
            puts("");
            return;
        }
    //  for the left
        for(int i = 0; i < tab; ++i) putchar('\t');

        printf("L ");

        print(current->left, tab+1);
    //  for the right
        for(int i = 0; i < tab; ++i) putchar('\t');

        printf("R ");
        
        print(current->right, tab+1);
    }
    void print(){
        print(root);
    }
    
    Node *remove(Node *current, int x){
        if(current == NULL){
            return NULL;
        }

        if(current->value < x){
            current->right = remove(current->right, x);
        }

        else if(current->value > x){
            current->left = remove(current->left, x);
        }

        else{
            if(current->left == NULL && current->right == NULL){
                delete current;
                return NULL;
            }
            if(current->left == NULL || current->right == NULL){
                Node *next = current->left == NULL ? current->left : current->right;
                delete current;
                return next;
            }
            
            Node *next = current->right;
            while(next->left != NULL){
                next = next->left;
            }

            current->value = next->value;

            current->right = remove(current->right, next->value);

        }
        
    }

    void remove(int x){
        root = remove(root, x);
    }
};



int main(){

    BST tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(9);
    tree.insert(7);
    tree.insert(0);
    tree.print();

    tree.remove(5);
    tree.print();

}