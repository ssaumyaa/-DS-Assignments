#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generate(int start, int end) {
    if (start > end) return {NULL};

    vector<TreeNode*> res;

    for (int root = start; root <= end; root++) {

        vector<TreeNode*> leftTrees = generate(start, root - 1);
        vector<TreeNode*> rightTrees = generate(root + 1, end);

        for (auto l : leftTrees)
            for (auto r : rightTrees) {
                TreeNode* node = new TreeNode(root);
                node->left = l;
                node->right = r;
                res.push_back(node);
            }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generate(1, n);
}

int main() {
    int n = 3;
    auto trees = generateTrees(n);
    cout << "Total BSTs = " << trees.size();  // Output: 5
}
