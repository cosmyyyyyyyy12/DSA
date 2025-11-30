#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                return 0;
            }
            else if(nums[i] < 0){
                cnt++;
            }
        }
        if(cnt % 2 == 0){
            return 1;
        }
        else{
            return -1;
        }
    }
};

int main(){
    Solution s;
    vector <int> arr = {-1,-2,-3,-4,3,2,1};
    cout << s.arraySign(arr) << "\n";
}