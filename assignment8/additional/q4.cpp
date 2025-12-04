#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        int last;

        while (sz--) {
            TreeNode* node = q.front(); q.pop();
            last = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.push_back(last);
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> view = rightSideView(root);
    cout << "Right View: ";
    for (int x : view) cout << x << " ";
    return 0;
}
