#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x){ data = x; left = right = NULL; }
};

bool findDuplicates(Node* root, unordered_set<int>& st) {
    if(!root) return false;

    if(st.count(root->data)) return true;
    st.insert(root->data);

    return findDuplicates(root->left, st) ||
           findDuplicates(root->right, st);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(5); // duplicate

    unordered_set<int> st;

    if(findDuplicates(root, st))
        cout << "Duplicates Found";
    else
        cout << "No Duplicates";
}
