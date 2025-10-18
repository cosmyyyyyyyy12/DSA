#include <iostream>
using namespace std;

int main() {
    int nums[6]={1,1,0,1,1,1};
    int i=0,j=0;
        int count=0;
        int maxx=0;
        while(j<6){
            if(i==j && nums[i]==1 && nums[j]==1){
                count = j-i+1;
                j++;
            }
            else if(nums[i]==1 && nums[j]==1){
                count = j-i+1;
                j++;
            }
            if(j<6 && nums[j]==0){
                i=j+1;
                j++;
            }
            maxx=max(maxx,count);
        }
        cout << maxx;
}