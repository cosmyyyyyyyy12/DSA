#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;
        unordered_map<int, int> m;

        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                m[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (m.count(nums1[i])) {
                nums1[i] = m[nums1[i]];
            } else {
                nums1[i] = -1;
            }
        }

        return nums1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}
