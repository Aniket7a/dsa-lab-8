#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int key) {
    Node* n = new Node();
    n->data = key;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int key) {
    if(root == NULL) return newNode(key);
    if(key < root->data) root->left = insert(root->left, key);
    else if(key > root->data) root->right = insert(root->right, key);
    return root;
}

Node* minValue(Node* root) {
    while(root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL) return root;
    if(key < root->data) root->left = deleteNode(root->left, key);
    else if(key > root->data) root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root) {
    if(root == NULL) return 0;
    if(!root->left && !root->right) return 1;
    if(!root->left) return 1 + minDepth(root->right);
    if(!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);

    root = deleteNode(root, 30);

    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;
}
