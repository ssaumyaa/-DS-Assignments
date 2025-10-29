#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* rotateLeft(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    //  Count length
    Node* temp = head;
    int len = 1;
    while (temp->next) {
        temp = temp->next;
        len++;
    }

    //  Adjust k
    k = k % len;
    if (k == 0) return head;

    //  Make it circular
    temp->next = head;

    //  Move to (len - k)th node
    int stepsToNewHead = len - k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    //  New head and break circle
    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
