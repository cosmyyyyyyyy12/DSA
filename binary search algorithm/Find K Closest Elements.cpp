#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector <pair<int,int>> v;
        vector <int> ans;
        for(int i=0;i<arr.size();i++){
            v.push_back({abs(arr[i]-x),i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++){
            ans.push_back(arr[v[i].second]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    vector <int> nums = {1,2,3,4,5};
    int k = 4, x = 3;
    vector<int> result = sol.findClosestElements(nums, k,x);

    cout << "output: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;


    return 0;
}
