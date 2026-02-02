#include <iostream>
#include <utility>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    // returns {isSumTree, sumOfSubtree}
    pair<bool, int> tsum(Node* root) {
        if (root == NULL)
            return make_pair(true, 0);

        // leaf node
        if (root->left == NULL && root->right == NULL)
            return make_pair(true, root->data);

        pair<bool, int> leftAns = tsum(root->left);
        pair<bool, int> rightAns = tsum(root->right);

        bool condition = (root->data == leftAns.second + rightAns.second);

        pair<bool, int> ans;
        if (leftAns.first && rightAns.first && condition) {
            ans.first = true;
            ans.second = 2 * root->data;  // sum of subtree
        } else {
            ans.first = false;
            ans.second = 0;
        }
        return ans;
    }

    bool isSumTree(Node* root) {
        return tsum(root).first;
    }
};

int main() {
    /*
            26
           /  \
         10    3
        / \     \
       4   6     3
    */

    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    Solution sol;

    if (sol.isSumTree(root))
        cout << "Tree is a Sum Tree" << endl;
    else
        cout << "Tree is NOT a Sum Tree" << endl;

    return 0;
}
