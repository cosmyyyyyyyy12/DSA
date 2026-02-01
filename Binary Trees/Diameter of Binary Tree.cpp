#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
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
    // returns height, updates diameter by reference
    int height(TreeNode* root, int &d) {
        if (root == NULL) return 0;

        int l = height(root->left, d);
        int r = height(root->right, d);

        d = max(d, l + r);   // update diameter

        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        height(root, d);
        return d;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}
