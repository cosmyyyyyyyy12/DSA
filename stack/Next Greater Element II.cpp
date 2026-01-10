#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> st;
        vector <int> ans;
        vector <int> ans2(nums.size()*2,-1);
        vector <int> ans3;

        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }

        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
        }

        for (int i = 0; i < ans.size(); i++) {
            while (!st.empty() && ans[st.top()] < ans[i]) {
                ans2[st.top()] = ans[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<nums.size();i++){
            ans3.push_back(ans2[i]);
        }
        
        return ans3;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1,2,1};
    vector<int> result = sol.nextGreaterElements(nums1);
    cout << "Daily Temperatures: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
