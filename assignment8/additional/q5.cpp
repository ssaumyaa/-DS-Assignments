#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* build(vector<int> &pre, vector<int> &in, int L, int R, int &preIdx, unordered_map<int,int> &mp) {
    if (L > R) return NULL;

    int rootVal = pre[preIdx++];
    TreeNode* root = new TreeNode(rootVal);

    int mid = mp[rootVal];
    root->left = build(pre, in, L, mid - 1, preIdx, mp);
    root->right = build(pre, in, mid + 1, R, preIdx, mp);

    return root;
}

TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
    unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
    int idx = 0;
    return build(preorder, inorder, 0, inorder.size() - 1, idx, mp);
}

int main() {
    vector<int> pre = {3,9,20,15,7};
    vector<int> in  = {9,3,15,20,7};

    TreeNode* root = buildTree(pre, in);
    cout << "Tree built successfully." << endl;
    return 0;
}
