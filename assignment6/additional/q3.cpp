#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

void insertEnd(Node** head, int val) {
    Node* newNode = new Node(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
Node* reverseKGroup(Node* head, int k) {
    if (!head) return NULL;

    Node* current = head;
    Node* newHead = NULL;
    Node* nextNode = NULL;
    int count = 0;

    while (current && count < k) {
        nextNode = current->next;
        current->next = current->prev;
        current->prev = nextNode;
        newHead = current;
        current = nextNode;
        count++;
    }

    if (nextNode != NULL) {
        Node* rest = reverseKGroup(nextNode, k);
        head->next = rest;
        if (rest)
            rest->prev = head;
    }

    
    return newHead;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << " <=> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 8);
    insertEnd(&head, 4);
    insertEnd(&head, 2);
    insertEnd(&head, 5);
    insertEnd(&head, 6);
    insertEnd(&head, 7);
    insertEnd(&head, 9);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
