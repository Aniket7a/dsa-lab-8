#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node* n = new Node();
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int key) {
    if(root == NULL) return newNode(key);
    if(key < root->data) root->left = insert(root->left, key);
    else if(key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* searchRec(Node* root, int key) {
    if(root == NULL || root->data == key) return root;
    if(key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchNonRec(Node* root, int key) {
    while(root != NULL && root->data != key) {
        if(key < root->data) root = root->left;
        else root = root->right;
    }
    return root;
}

Node* minValue(Node* root) {
    while(root->left != NULL) root = root->left;
    return root;
}

Node* maxValue(Node* root) {
    while(root->right != NULL) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* n) {
    if(n->right != NULL) return minValue(n->right);
    Node* succ = NULL;
    while(root != NULL) {
        if(n->data < root->data) {
            succ = root;
            root = root->left;
        } else if(n->data > root->data)
            root = root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* n) {
    if(n->left != NULL) return maxValue(n->left);
    Node* pre = NULL;
    while(root != NULL) {
        if(n->data > root->data) {
            pre = root;
            root = root->right;
        } else if(n->data < root->data)
            root = root->left;
        else break;
    }
    return pre;
}

int main() {
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);

    Node* n = searchRec(root, 10);
    cout << minValue(root)->data << endl;
    cout << maxValue(root)->data << endl;
    cout << inorderSuccessor(root, n)->data << endl;
    cout << inorderPredecessor(root, n)->data << endl;
}
