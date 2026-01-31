#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        int cnt = 0;

        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                cnt++;
                if (!q.empty())
                    q.push(NULL);
            } else {
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return cnt;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution sol;
    cout << "Max Depth: " << sol.maxDepth(root) << endl;

    return 0;
}
