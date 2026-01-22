#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid;
        while(s<=e){
            mid = s+(e-s)/2;
            if(mid-1>=0 && mid+1<=nums.size()-1 && nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(mid+1<=nums.size()-1 && nums[mid]<nums[mid+1]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return mid;
    }
};

int main() {
    Solution sol;

    vector <int> nums = {1,2,3,1};
    int result = sol.findPeakElement(nums);

    cout << "output: " << result << endl;

    return 0;
}
