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

// Function to reverse K nodes at a time
Node* reverseKGroup(Node* head, int k) {
    if (head == NULL)
        return NULL;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    // Step 1: Check if there are at least k nodes left
    Node* temp = head;
    int nodeCount = 0;
    while (temp != NULL && nodeCount < k) {
        temp = temp->next;
        nodeCount++;
    }
    if (nodeCount < k) // Less than k nodes, don't reverse
        return head;

    // Step 2: Reverse first k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 3: Recurse for the remaining nodes
    if (next != NULL)
        head->next = reverseKGroup(next, k);

    // Step 4: prev is the new head of this reversed group
    return prev;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Input: 1->2->3->4->5->6->7->8->9, K=3
    Node* head = new Node(1);
    Node* curr = head;
    for (int i = 2; i <= 9; i++) {
        curr->next = new Node(i);
        curr = curr->next;
    }

    int k = 3;
    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
