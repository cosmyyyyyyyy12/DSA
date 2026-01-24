#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int s = 0;
        int e = arr.size()-1;
        vector <int> ans;
        while(e-s>=k){
            if(x - arr[s] > arr[e] - x){
                s++;
            }
            else{
                e--;
            }
        }
        for(int i = s;i<=e;i++){
            ans.push_back(arr[i]);
        }
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
