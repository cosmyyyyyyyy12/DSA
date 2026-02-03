#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> traversal(TreeNode* root){
        bool left_to_right = true;

        queue<TreeNode*> q;

        vector <int> semi_ans;

        vector<vector<int>> ans;

        if(root == NULL) return ans;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* temp = q.front();

            if(temp != NULL) semi_ans.push_back(temp->val);
            
            q.pop();

            if(temp == NULL){

                if(!left_to_right) reverse(semi_ans.begin(),semi_ans.end());
                ans.push_back(semi_ans);

                if(!q.empty()){
                    semi_ans.clear();
                    left_to_right = !left_to_right;
                    q.push(NULL);
                }
            }

            else{

                if(temp->left) q.push(temp->left);

                if(temp->right) q.push(temp->right);
            }
        }

        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return traversal(root);
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    for (auto level : result) {
        for (int x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
