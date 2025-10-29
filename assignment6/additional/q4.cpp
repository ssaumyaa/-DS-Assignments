#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

void fixRandomPointer(Node* head) {
    Node* curr = head;

    while (curr && curr->next) {
        // if the next node's prev doesn't point back correctly
        if (curr->next->prev != curr) {
            cout << "Inconsistency found at node " << curr->data << endl;

            // find the node whose prev is wrong
            Node* temp = curr->next;
            while (temp && temp->prev != curr)
                temp = temp->next;

            // fix the broken link
            if (temp) {
                curr->next->prev = curr;
                cout << "Pointer fixed at node " << curr->next->data << endl;
            }
            else {
                // If next pointer is wrong, fix it
                curr->next = curr->next->next;
                if (curr->next)
                    curr->next->prev = curr;
                cout << "Next pointer corrected for node " << curr->data << endl;
            }
            break; 
        }
        curr = curr->next;
    }
}

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* n1 = new Node(20);
    Node* n2 = new Node(30);
    Node* n3 = new Node(40);
    Node* n4 = new Node(50);

    head->next = n1; n1->prev = head;
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

   
    n2->next = head; 

    cout << "Before fixing:\n";
    printList(head); 

    fixRandomPointer(head);

    cout << "\nAfter fixing:\n";
    printList(head);
}
