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

    bool isSame(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;

        return isSame(p->left, q->left) &&
               isSame(p->right, q->right);
    }

    bool traverse(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        if (isSame(root, subRoot))
            return true;

        return traverse(root->left, subRoot) ||
               traverse(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return traverse(root, subRoot);
    }
};

int main() {

    /*
            3
           / \
          4   5
         / \
        1   2
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    /*
          4
         / \
        1   2
    */

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;

    if (sol.isSubtree(root, subRoot))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
