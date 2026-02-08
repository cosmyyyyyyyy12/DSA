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
    void solve(TreeNode* root, int targetSum, vector<int> path, int &count) {
        if (!root) return;

        path.push_back(root->val);

        solve(root->left, targetSum, path, count);
        solve(root->right, targetSum, path, count);

        long long sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == targetSum)
                count++;
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int count = 0;
        solve(root, targetSum, path, count);
        return count;
    }
};

int main() {

    /*
            10
           /  \
          5   -3
         / \    \
        3   2    11
       / \   \
      3  -2    1
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution sol;
    int target = 8;

    int result = sol.pathSum(root, target);

    cout << "Number of paths with sum " << target << " = " << result << endl;

    return 0;
}
