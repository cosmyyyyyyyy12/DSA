#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    void solve(TreeNode* root, int &cnt, int maxx) {
        if (!root) return;

        if (root->val >= maxx)
            cnt++;

        maxx = max(maxx, root->val);

        solve(root->left, cnt, maxx);
        solve(root->right, cnt, maxx);
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int cnt = 0;
        solve(root, cnt, root->val);

        return cnt;
    }
};

int main() {

    /*
            3
           / \
          1   4
             / \
            1   5
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    Solution sol;
    cout << "Good Nodes: " << sol.goodNodes(root);

    return 0;
}
