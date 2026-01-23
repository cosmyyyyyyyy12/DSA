#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int first(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int mid, ans = -1;
        while(s<=e){
            mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }

    int ec(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int mid, ans = -1;
        while(s<=e){
            mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target),ec(nums,target)};
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);

    cout << "output: [";
    cout << result[0] << ", " << result[1];
    cout << "]" << endl;

    return 0;
}

