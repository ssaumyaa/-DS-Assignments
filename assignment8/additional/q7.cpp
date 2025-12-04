#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x): val(x), left(NULL), right(NULL) {}
};

void bstToDLL(Node* root, Node* &head, Node* &prev) {
    if (!root) return;

    bstToDLL(root->left, head, prev);

    if (!head) head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

Node* mergeDLL(Node* a, Node* b) {
    Node dummy(0);
    Node* tail = &dummy;

    while (a && b) {
        if (a->val < b->val) {
            tail->right = a;
            a->left = tail;
            a = a->right;
        } else {
            tail->right = b;
            b->left = tail;
            b = b->right;
        }
        tail = tail->right;
    }

    Node* rem = (a ? a : b);
    tail->right = rem;
    if (rem) rem->left = tail;

    return dummy.right;
}

int main() {
    Node* a = new Node(2);
    a->left = new Node(1);
    a->right = new Node(3);

    Node* b = new Node(5);
    b->left = new Node(4);
    b->right = new Node(6);

    Node *head1=NULL, *prev1=NULL;
    bstToDLL(a, head1, prev1);

    Node *head2=NULL, *prev2=NULL;
    bstToDLL(b, head2, prev2);

    Node* merged = mergeDLL(head1, head2);

    cout << "Merged DLL: ";
    while (merged) {
        cout << merged->val << " ";
        merged = merged->right;
    }
    return 0;
}
