#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {

        int x = 0;
        int y = 0;

        // Count number of drops
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                x = 1;
                y++;
            }
        }

        // Already sorted
        if (!x)
            return true;

        // More than one drop -> not valid
        if (y > 1)
            return false;

        // Check rotation condition
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1] &&
                nums[0] >= nums[nums.size() - 1])
                return true;
        }

        return false;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {3, 4, 5, 1, 2};

    if (sol.check(nums))
        cout << "True";
    else
        cout << "False";

    return 0;
}