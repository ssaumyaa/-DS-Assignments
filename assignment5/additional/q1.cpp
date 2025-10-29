#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (headA == NULL || headB == NULL)
        return NULL;

    Node* a = headA;
    Node* b = headB;

    while (a != b) {
        if (a == NULL)
            a = headB;
        else
            a = a->next;

        if (b == NULL)
            b = headA;
        else
            b = b->next;
    }

    return a; 
}

int main() {
    // Common part: 8 -> 5
    Node* common = new Node(8);
    common->next = new Node(5);

    // First list: 4 -> 1 -> 8 -> 5
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = common;

    // Second list: 5 -> 6 -> 1 -> 8 -> 5
    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = common;

    Node* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL)
        cout << "Intersected at " << intersection->data << endl;
    else
        cout << "No intersection" << endl;

    return 0;
}
