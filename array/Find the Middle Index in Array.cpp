#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return s; // Insert position
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    cout << "Insert Position: "
         << sol.findMiddleIndex(nums, target);

    return 0;
}
