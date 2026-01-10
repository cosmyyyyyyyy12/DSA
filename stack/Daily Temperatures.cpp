#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector <int> ans(temperatures.size(),0);
        stack <int> st;
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {73,74,75,71,69,72,76,73};
    vector<int> result = sol.dailyTemperatures(nums1);
    cout << "Daily Temperatures: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
