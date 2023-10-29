#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *left, *right;
    int value;

    Node(int value = 0){
        left = right = NULL;
        this->value = value;
    }

    Node(int value, Node *left, Node *right){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BST{
    Node *root = NULL;

private:
    Node *push(Node *root, int x, int y, int z){
        Node *temp = search(root, x);
        if(z == 1) temp->right = new Node(y);
        else temp->left = new Node(y);

        return temp;
    }
public:
    void insert(int x, int y, int z){
        root = push(root, x, y, z);
    }

    Node* search(Node* current, int x) {
    if (current) {
        if (current->value == x) {
            return current;
        } else {
            Node* leftResult = search(current->left, x);
            if (leftResult) {
                return leftResult;
            } else {
                return search(current->right, x);
            }
        }
    }
    return NULL;
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

        printf("L ");

        print(current->left, tab+1);

        

    //  for the left
        for(int i = 0; i < tab; ++i) putchar('\t');

        printf("R ");
        
        print(current->right, tab+1);
    }

    void print(){
        print(root);
    }



};

int main(){

    BST tree;

    int n; cin >> n;

    for(int i = 0; i < n-1; ++i){
        int x, y, z; cin >> x >> y >> z;
        tree.insert(x, y, z);
    }
    
    tree.print();

}