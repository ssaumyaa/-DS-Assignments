#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

Node* addPolynomial(Node* head1, Node* head2) {
    Node* dummy = new Node(0, 0);
    Node* temp = dummy;

    while (head1 && head2) {
        if (head1->pow == head2->pow) {
            temp->next = new Node(head1->coeff + head2->coeff, head1->pow);
            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->pow > head2->pow) {
            temp->next = new Node(head1->coeff, head1->pow);
            head1 = head1->next;
        }
        else {
            temp->next = new Node(head2->coeff, head2->pow);
            head2 = head2->next;
        }
        temp = temp->next;
    }

    // Attach remaining terms (if any)
    while (head1) {
        temp->next = new Node(head1->coeff, head1->pow);
        head1 = head1->next;
        temp = temp->next;
    }

    while (head2) {
        temp->next = new Node(head2->coeff, head2->pow);
        head2 = head2->next;
        temp = temp->next;
    }

    return dummy->next;
}
