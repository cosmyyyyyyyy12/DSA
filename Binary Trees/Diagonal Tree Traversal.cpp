#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> diagonal(Node* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            while (node) {
                ans.push_back(node->data);

                if (node->left)
                    q.push(node->left);

                node = node->right;
            }
        }
        return ans;
    }
};

int main() {

    /*
            8
          /   \
         3     10
        / \      \
       1   6      14
          / \     /
         4   7   13
    */

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    Solution sol;
    vector<int> result = sol.diagonal(root);

    cout << "Diagonal Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
