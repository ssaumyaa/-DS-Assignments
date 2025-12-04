#include <bits/stdc++.h>
using namespace std;

struct MaxHeap {
    vector<int> h;

    void heapify(int i) {
        int n = h.size();
        int largest = i;
        int l = 2*i + 1, r = 2*i + 2;

        if (l < n && h[l] > h[largest]) largest = l;
        if (r < n && h[r] > h[largest]) largest = r;

        if (largest != i) {
            swap(h[i], h[largest]);
            heapify(largest);
        }
    }

    void push(int x) {
        h.push_back(x);
        int i = h.size() - 1;

        while (i > 0 && h[(i-1)/2] < h[i]) {
            swap(h[i], h[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int top() {
        if (h.empty()) return -1;
        return h[0];
    }

    void pop() {
        if (h.empty()) return;
        h[0] = h.back();
        h.pop_back();
        heapify(0);
    }

    bool empty() { return h.empty(); }
};

int main() {
    MaxHeap pq;
    pq.push(50);
    pq.push(20);
    pq.push(60);
    pq.push(10);

    cout << "Top element = " << pq.top() << endl;
    pq.pop();
    cout << "After pop, new top = " << pq.top() << endl;

    return 0;
}
