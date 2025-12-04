#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){ data = x; next = NULL; }
};

Node* insertEnd(Node* head, int val) {
    Node* n = new Node(val);
    if(!head) return n;
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = n;
    return head;
}

void printList(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* getUnion(Node* head1, Node* head2) {
    unordered_set<int> st;
    Node* result = NULL;

    Node* temp = head1;
    while(temp) {
        st.insert(temp->data);
        temp = temp->next;
    }
    temp = head2;
    while(temp) {
        st.insert(temp->data);
        temp = temp->next;
    }

    for(int x : st)
        result = insertEnd(result, x);

    return result;
}

Node* getIntersection(Node* head1, Node* head2) {
    unordered_set<int> st;
    Node* result = NULL;

    Node* temp = head1;
    while(temp) {
        st.insert(temp->data);
        temp = temp->next;
    }

    temp = head2;
    while(temp) {
        if(st.count(temp->data))
            result = insertEnd(result, temp->data);
        temp = temp->next;
    }
    return result;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    head1 = insertEnd(head1, 10);
    head1 = insertEnd(head1, 15);
    head1 = insertEnd(head1, 4);
    head1 = insertEnd(head1, 20);

    head2 = insertEnd(head2, 8);
    head2 = insertEnd(head2, 4);
    head2 = insertEnd(head2, 2);
    head2 = insertEnd(head2, 10);

    Node* inter = getIntersection(head1, head2);
    Node* uni = getUnion(head1, head2);

    cout << "Intersection: ";
    printList(inter);

    cout << "Union: ";
    printList(uni);
}
