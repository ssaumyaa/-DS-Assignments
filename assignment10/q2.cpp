#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int>& A, vector<int>& B) {
    unordered_set<int> st(A.begin(), A.end());
    vector<int> result;

    for(int x : B)
        if(st.count(x))
            result.push_back(x);

    return result;
}

int main() {
    vector<int> A = {1,2,3,4};
    vector<int> B = {3,4,5,6};

    vector<int> ans = commonElements(A,B);
    for(int x : ans) cout << x << " ";
}
