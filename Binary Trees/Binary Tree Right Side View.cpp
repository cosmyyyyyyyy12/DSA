#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void solve(TreeNode* root, vector<int>& ans, int level) {
        if (!root) return;

        // If first time visiting this level
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        // Visit right first
        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
           \   \
            5   4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
