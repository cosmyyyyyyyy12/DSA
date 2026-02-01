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
    pair <bool,int> height(TreeNode* root){
        if(root == NULL) return make_pair(true,0);
        pair <bool,int> l = height(root->left);
        pair <bool,int> r = height(root->right);
        bool diff = abs(l.second - r.second) <= 1;
        pair <bool,int> ans;
        ans.second = 1+max(l.second,r.second);
        if(l.first && r.first && diff) ans.first = true;
        else ans.first = false;
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return height(root).first;
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
    cout << sol.isBalanced(root) << endl;

    return 0;
}