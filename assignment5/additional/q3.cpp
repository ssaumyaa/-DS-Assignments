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

void removeLoop(Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop using Floyd’s Cycle-Finding
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast)
            break;
    }

    // Step 2: If loop exists
    if (slow == fast) {
        slow = head;

        // Special case: if the loop starts at head
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } else {
            // Move slow and fast one step at a time
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Break the loop
        fast->next = NULL;
    }
}

void printList(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < 30) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
        count++;
    }
    cout << endl;
}

int main() {
    // Creating list: 1->7->3->6
    Node* head = new Node(1);
    head->next = new Node(7);
    head->next->next = new Node(3);
    head->next->next->next = new Node(6);

    head->next->next->next->next = head->next;

    removeLoop(head);
    cout << "Linked List after removing loop: ";
    printList(head);

    return 0;
}
