#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;

    int sum = 0;

    if (root->left) {
        if (isLeaf(root->left)) 
            sum += root->left->val;    
        else 
            sum += sumOfLeftLeaves(root->left);
    }


    sum += sumOfLeftLeaves(root->right);

    return sum;
}

TreeNode* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front(); q.pop();


        if (arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;


        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    vector<int> arr = {3,9,20,-1,-1,15,7};
    TreeNode* root = buildTree(arr);
    cout << sumOfLeftLeaves(root);  // Output: 24
}
