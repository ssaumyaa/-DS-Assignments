#include <bits/stdc++.h>
using namespace std;

int mostFrequent(vector<int>& arr) {
    unordered_map<int,int> freq;

    for(int x : arr)
        freq[x]++;

    int maxFreq = 0, ans = INT_MIN;

    for(auto &p : freq) {
        int val = p.first;
        int count = p.second;

        if(count > maxFreq || (count == maxFreq && val > ans)) {
            maxFreq = count;
            ans = val;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 2, 4, 1};
    cout << mostFrequent(arr);
}
