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

void insertEnd(Node** head, int val) {
    Node* newNode = new Node(val);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    if (head == NULL)
        return;

    Node* slow = head;
    Node* fast = head;

    // Move fast by 2 and slow by 1
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // For even number of nodes, move fast one more step
    if (fast->next->next == head)
        fast = fast->next;

    // Set heads of two halves
    *head1_ref = head;
    if (head->next != head)
        *head2_ref = slow->next;

    // Make first half circular
    fast->next = slow->next;

    // Make second half circular
    slow->next = head;
}

void printList(Node* head) {
    if (head == NULL)
        return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* head1 = NULL;
    Node* head2 = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 4);
    insertEnd(&head, 9);

    splitList(head, &head1, &head2);

    cout << "First half: ";
    printList(head1);

    cout << "Second half: ";
    printList(head2);

    return 0;
}
