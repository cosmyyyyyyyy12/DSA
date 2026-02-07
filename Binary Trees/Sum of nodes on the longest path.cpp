#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void solve(Node* root, int len, int &maxLen, int sum, int &maxSum) {
        if (!root) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } 
            else if (len == maxLen) {
                maxSum = max(sum, maxSum);
            }
            return;
        }

        sum += root->data;

        solve(root->left, len + 1, maxLen, sum, maxSum);
        solve(root->right, len + 1, maxLen, sum, maxSum);
    }

    int sumOfLongRootToLeafPath(Node* root) {
        int len = 0;
        int maxLen = 0;
        int sum = 0;
        int maxSum = INT_MIN;

        solve(root, len, maxLen, sum, maxSum);

        return maxSum;
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

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    int result = sol.sumOfLongRootToLeafPath(root);

    cout << "Sum of Longest Root-to-Leaf Path: " << result << endl;

    return 0;
}
