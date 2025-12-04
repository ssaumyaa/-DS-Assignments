#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSortIncreasing(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void heapSortDecreasing(vector<int>& a) {
    heapSortIncreasing(a);
    reverse(a.begin(), a.end());
}

int main() {
    vector<int> v = {10, 40, 20, 5, 60};

    heapSortIncreasing(v);
    cout << "Increasing order: ";
    for (int x : v) cout << x << " ";

    cout << "\n";

    heapSortDecreasing(v);
    cout << "Decreasing order: ";
    for (int x : v) cout << x << " ";

    return 0;
}
