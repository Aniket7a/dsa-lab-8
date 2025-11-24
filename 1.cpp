#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* n = new Node();
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
}
