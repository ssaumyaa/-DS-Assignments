#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st;
    for(int x : nums) {
        if(st.count(x)) return true;
        st.insert(x);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << (containsDuplicate(nums) ? "true" : "false");
}
