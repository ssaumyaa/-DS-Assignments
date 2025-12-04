#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build(vector<int> &in, vector<int> &post, int L, int R, int &postIdx, unordered_map<int,int> &mp) {
    if (L > R) return NULL;

    int rootVal = post[postIdx--];
    TreeNode* root = new TreeNode(rootVal);

    int mid = mp[rootVal];
    root->right = build(in, post, mid + 1, R, postIdx, mp);
    root->left = build(in, post, L, mid - 1, postIdx, mp);

    return root;
}

TreeNode* buildTree(vector<int> inorder, vector<int> postorder) {
    unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

    int postIdx = postorder.size() - 1;
    return build(inorder, postorder, 0, inorder.size() - 1, postIdx, mp);
}

int main() {
    vector<int> in = {9,3,15,20,7};
    vector<int> post = {9,15,7,20,3};

    TreeNode* root = buildTree(in, post);
    cout << "Tree built successfully." << endl;
    return 0;
}
