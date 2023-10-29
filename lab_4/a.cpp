#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *left, *right;
    int value;
    Node(int value = 0){
        right = left = NULL;
        this->value = value;
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

    void answer(string s){
        bool ok = true;
        Node *current = root;
        for(int i =0; i < s.size(); ++i){
            if(s[i] == 'L') current = current->left;
            if(s[i] == 'R') current = current->right;
            if(current == NULL){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << "\n";
        }

    }

    void print(Node *current, int tab = 1){

        // cout << root->value << endl;
        // cout << root->left->value<< endl;
        // cout << root->right->value<< endl;
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

    int n, m; cin >> n >> m;

    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        tree.insert(x);
    }
    // tree.print();
    for(int i = 0; i < m; ++i){
        string s;
        cin >> s;
        tree.answer(s);
    }
}