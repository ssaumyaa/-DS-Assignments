#include <bits/stdc++.h>
using namespace std;

int firstNonRepeating(vector<int>& nums) {
    unordered_map<int,int> mp;
    for(int x : nums) mp[x]++;

    for(int x : nums)
        if(mp[x] == 1)
            return x;

    return -1;
}

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};
    cout << firstNonRepeating(nums);
}
