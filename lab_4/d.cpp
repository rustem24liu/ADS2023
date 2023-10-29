#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *right, *left;
    int value;
    Node(int value = 0){
        this->value = value;
        right = left = NULL;
    }
    Node(int value, Node *right, Node *left){
        this->value = value;
        this->right = right;
        this->left= left;
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


    void sumOfLevels(Node *  current,vector <int> &v, int x){
        if(current == NULL) return;
        if(v.size() <= x) v.push_back(current->value);
        else{
            v[x] += current->value;
        }

        sumOfLevels(current->left, v, x+1);
        sumOfLevels(current->right, v, x+1);
    }
};

int main(){

    BST tree;

    vector <int> v;
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        tree.insert(x);
    }
    
    tree.sumOfLevels(tree.root, v, 0);
    cout << v.size() << "\n";
    for(int i =0;i < v.size(); ++i){
        cout << v[i] << " ";
    }


}