#include <iostream>
#include <queue>
using namespace std;

int minIndex(queue<int> &q, int n) {
    int min_index = -1;
    int min_val = INT_MAX;
    int size = q.size();
    for (int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();

        // Find min among first n elements
        if (i < n && curr < min_val) {
            min_val = curr;
            min_index = i;
        }

        // Push back current element
        q.push(curr);
    }
    return min_index;
}

// Move min element to rear
void moveMinToRear(queue<int> &q, int min_index) {
    int size = q.size();
    int min_val;
    for (int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();
        if (i != min_index)
            q.push(curr);
        else
            min_val = curr; // found min
    }
    q.push(min_val);
}

void sortQueue(queue<int> &q) {
    for (int i = 1; i <= q.size(); i++) {
        int min_index = minIndex(q, q.size() - i + 1);
        moveMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
