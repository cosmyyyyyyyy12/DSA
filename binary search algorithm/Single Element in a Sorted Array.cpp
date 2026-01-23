#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid;
        while(s<e){
            mid = s + (e-s)/2;
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 != 0 && nums[mid] == nums[mid - 1])){
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

    vector <int> nums = {1,1,2,3,3,4,4,8,8};
    int result = sol.singleNonDuplicate(nums);

    cout << "output: " << result << endl;

    return 0;
}
