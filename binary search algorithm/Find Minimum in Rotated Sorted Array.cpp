#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid;
        while(s<e){
            mid = s+(e-s)/2;
            if(nums[mid] >= nums[e]){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        return nums[s];
    }
};

int main() {
    Solution sol;

    vector <int> n = {3,4,5,1,2};
    int result = sol.findMin(n);

    cout << "output: " << result << endl;

    return 0;
}
