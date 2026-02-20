#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int minn = *min_element(nums.begin(), nums.end());
        int maxx = *max_element(nums.begin(), nums.end());

        int s1, s2, s3;
        int cnt;
        int var;

        // ----------------
        // Scene 1: remove from front
        // ----------------
        cnt = 0;
        var = 2;

        for (int i = 0; i < nums.size(); i++) {
            cnt++;
            if (nums[i] == minn || nums[i] == maxx)
                var--;

            if (var == 0)
                break;
        }

        s1 = cnt;

        // ----------------
        // Scene 2: remove from back
        // ----------------
        cnt = 0;
        var = 2;

        for (int i = nums.size() - 1; i >= 0; i--) {
            cnt++;
            if (nums[i] == minn || nums[i] == maxx)
                var--;

            if (var == 0)
                break;
        }

        s2 = cnt;

        // ----------------
        // Scene 3: one from front, one from back
        // ----------------
        cnt = 0;

        // from front until we hit either min or max
        for (int i = 0; i < nums.size(); i++) {
            cnt++;
            if (nums[i] == minn || nums[i] == maxx)
                break;
        }

        // from back until we hit the other
        for (int i = nums.size() - 1; i >= 0; i--) {
            cnt++;
            if (nums[i] == minn || nums[i] == maxx)
                break;
        }

        s3 = cnt;

        return min(s1, min(s2, s3));
    }
};

int main() {

    Solution sol;

    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};

    cout << "Minimum deletions: "
         << sol.minimumDeletions(nums);

    return 0;
}