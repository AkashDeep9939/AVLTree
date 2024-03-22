#include<iostream>
using namespace std;

class Node {

    public:
    int data, height;
    Node *left, *right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

int getbalance(Node *root) {
    return getheight(root->left) - getheight(root->right);
}

int getheight(Node* root) {
    if(!root)
    return 0;

    return root->height;

}

Node* insert(Node *root, int key) {

    // Dosn't exist
    if(!root)
    return new Node(key);

    // Exist hai
    if(key < root->data) // left side
    root->left = insert(root->left,key);
    else if(key>root->data) // right side
    root->right = insert(root->right,key);
    else
    return root; // Duplicate elements are not allowed

    // Update height 
    root->height = 1+max(getheight(root->left), getheight(root->right));

    // Balancing check
    int balance = getbalance(root);

    // Left Left case

    // Right Right case

    // Left Right case 

    //Right Left case 
    

}


int main() {

    Node *root = NULL;

    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,50);
    root = insert(root,70);
    root = insert(root,5);
    root = insert(root,100);
    root = insert(root,95);
}