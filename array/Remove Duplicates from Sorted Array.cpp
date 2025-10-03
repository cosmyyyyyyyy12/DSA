#include <iostream>
#include <vector>
using namespace std;
int main(){
    int nums[3] = {1,1,2};
    int j=1;
        vector <int> ans;
        ans.push_back(nums[j-1]);
        for(int i=1;i<3;i++){
            if(nums[i]!=nums[j-1]){
                ans.push_back(nums[i]);
            }
            j++;
        }
        for(int i=1;i<ans.size();i++){
            nums[i]=ans[i];
        }
        cout << ans.size();
}