#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int area = 0;

        while (i < j) {
            area = max(area, min(height[i], height[j]) * (j - i));

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return area;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = sol.maxArea(height);
    cout << "Maximum Area: " << result << endl;
    return 0;
}
