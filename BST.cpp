#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* rigth;

    Node(int value) {
        data = value;
        left = right =NULL;
    }
};

class BST {
    public:
    Node* root;

    BST() {
        root = NULL;
    }
    //insert
    Node* insert(Node* root, int value) {
        if (root ==NULL) {
            return new Node(value);
        }
        if (value < root-> data) {
            root->left = insert(root->left,value);
        } else if (value > root ->data) {
            root ->right = insert(root->right, value);
        }
        return root;
    }
    //Inorder(Sorted)
    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root-> right);
    }
    //search
    bool search(Node* root, int key) {
        if (root == NULL) return false;

        if (root->data == key)
        return true;

        if(key< root-> data)
        return search(root->left, key);
        else
        return search(root-> right, key);
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout<<"Inorder Traversal: ";
    tree.iorder(tree.root);
    cout<<"\n Search 40: "<<(tree.search(tree.root, 40) ? " Found" : "Not Found");
    cout<<"\n Search 90: "<<(tree.search(tree.root, 90) ? " Found" : "Not Found");

    return 0;

}