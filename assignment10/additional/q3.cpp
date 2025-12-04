#include <bits/stdc++.h>
using namespace std;

bool areEqual(vector<int>& a, vector<int>& b) {
    if(a.size() != b.size()) return false;

    unordered_map<int,int> freq;

    for(int x : a) freq[x]++;
    for(int x : b) freq[x]--;

    for(auto &p : freq)
        if(p.second != 0)
            return false;

    return true;
}

int main() {
    vector<int> a = {1, 2, 5, 4, 0};
    vector<int> b = {2, 4, 5, 0, 1};

    cout << (areEqual(a, b) ? "true" : "false");
}
