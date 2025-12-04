#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

bool isBSTUtil(Node* root, long long minV, long long maxV) {
    if (!root) return true;
    if (root->key <= minV || root->key >= maxV) return false;

    return isBSTUtil(root->left, minV, root->key) &&
           isBSTUtil(root->right, root->key, maxV);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    cout << (isBST(root) ? "Tree is BST\n" : "Tree is NOT BST\n");
    return 0;
}
