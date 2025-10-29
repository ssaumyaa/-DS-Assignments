#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

// Count parity (1 = odd, 0 = even)
int countParity(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count % 2;
}

// Insert node at end (circular)
void insertEnd(CNode** head, int val) {
    CNode* newNode = new CNode(val);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    CNode* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

// Remove even-parity nodes
void removeEvenParityCLL(CNode** head) {
    // if list is empty
    if (*head == NULL)
        return;

    CNode* curr = *head;
    CNode* prev = NULL;

    while (countParity(curr->data) == 0) {
        // Case: only one node in list (and it has even parity)
        if (curr->next == *head) {
            *head = NULL; // entire list removed
            return;
        }

        // Find last node (the one pointing back to head)
        CNode* last = *head;
        while (last->next != *head)
            last = last->next;

        // Delete current head node
        CNode* temp = curr;
        *head = curr->next;  
        last->next = *head;  
        curr = *head;         
        delete temp;          
    }

    // STEP 2: Now handle rest of the list normally
    prev = curr;
    curr = curr->next;

    while (curr != *head) {
        // if current node has even parity
        if (countParity(curr->data) == 0) {
            prev->next = curr->next; 
            delete curr;      
            curr = prev->next;   
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

void insertEnd(DNode** head, int val) {
    DNode* newNode = new DNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    DNode* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void removeEvenParity(DNode** head) {
    DNode* curr = *head;
    while (curr) {
        if (countParity(curr->data) == 0) { // even
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                *head = curr->next; // deleting head

            if (curr->next)
                curr->next->prev = curr->prev;

            DNode* temp = curr;
            curr = curr->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
}

void printList(DNode* head) {
    DNode* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next)
            cout << " <=> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    DNode* head = NULL;
    insertEnd(&head, 18);
    insertEnd(&head, 15);
    insertEnd(&head, 8);
    insertEnd(&head, 9);
    insertEnd(&head, 14);

    removeEvenParity(&head);

    cout << "Updated Doubly List: ";
    printList(head);
    return 0;
}


int main() {
    CNode* head1 = NULL;
    insertEnd(&head1, 9);
    insertEnd(&head1, 11);
    insertEnd(&head1, 34);
    insertEnd(&head1, 6);
    insertEnd(&head1, 13);
    insertEnd(&head1, 21);

    removeEvenParityCLL(&head1);

    cout << "Updated Circular List: ";
    printList(head1);
  DNode* head2 = NULL;
    insertEnd(&head2, 18);
    insertEnd(&head2, 15);
    insertEnd(&head2, 8);
    insertEnd(&head2, 9);
    insertEnd(&head2, 14);

    removeEvenParity(&head2);

    cout << "Updated Doubly List: ";
    printList(head2);
    return 0;
    return 0;
}
