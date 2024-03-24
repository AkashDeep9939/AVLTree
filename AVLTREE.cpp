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

// Right rotation
Node* rightRotation(Node *root) {
    Node *child = root->left;
    Node *childRight = child->right;

    // Update the height
    root->height = 1+ max(getheight(root->left), getheight(root->right));
    child->height = 1+ max(getheight(child->left), getheight(child->right));

    return child;
}

//Left rotation
Node* leftRotation(Node *root) {
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    root->height = 1+ max(getheight(root->left), getheight(root->right));
    child->height = 1+ max(getheight(child->left), getheight(child->right));
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
    if(balance > 1 && root->left->data)
    return rightRotation(root);

    // Right Right case
    else if(balance < -1 && root->right->data<key)
    return leftRotation(root);

    // Left Right case
    else if (balance > 1 && key>root->left->data){
    root->left =  leftRotation(root->left);
    return  rightRotation(root);
    }


    //Right Left case 
    else if (balance < -1 && root->right->data>key){
    root->left =  rightRotation(root->right);
     return leftRotation(root);
    }

    // No Unbalancing case
    else
    return root;
}

void preorder(Node *root){
    if(!root)
    return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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

    cout<<"preorder: "<<endl;

}