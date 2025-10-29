#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;  
    Node* up;  
    Node* down;  
    Node(int val) : data(val), next(NULL), prev(NULL), up(NULL), down(NULL) {}
};

Node* convertToLinkedGrid(int mat[10][10], int m, int n) {

    Node* nodes[10][10];   

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            nodes[i][j] = new Node(mat[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) nodes[i][j]->prev = nodes[i][j - 1];   
            if (j < n - 1) nodes[i][j]->next = nodes[i][j + 1];
            if (i > 0) nodes[i][j]->up = nodes[i - 1][j];    
            if (i < m - 1) nodes[i][j]->down = nodes[i + 1][j]; 
        }
    }

    
    return nodes[0][0];
}

void printLinkedGrid(Node* head, int m, int n) {
    Node* row = head;
    while (row != NULL) {
        Node* col = row;
        while (col != NULL) {
            cout << col->data << " ";
            col = col->next;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    int mat[10][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int m = 3, n = 3;

    Node* head = convertToLinkedGrid(mat, m, n);

    cout << "Doubly linked grid:" << endl;
    printLinkedGrid(head, m, n);

    return 0;
}
