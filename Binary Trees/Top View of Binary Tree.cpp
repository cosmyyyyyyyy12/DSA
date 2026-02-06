#include <iostream>
#include <queue>
#include <map>
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
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, int> m;   // hd -> node value
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            // store first node at this horizontal distance
            if (m.find(hd) == m.end()) {
                m[hd] = frontNode->data;
            }

            if (frontNode->left)
                q.push({frontNode->left, hd - 1});
            if (frontNode->right)
                q.push({frontNode->right, hd + 1});
        }

        for (auto i : m) {
            ans.push_back(i.second);
        }

        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5    6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    vector<int> result = sol.topView(root);

    cout << "Top View: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
