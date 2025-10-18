#include <iostream>
using namespace std;

int main() {
    int nums[5]={0,1,0,3,12};
    int i=0,j=1;
        while(j<5){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[i]==0 && nums[j]==0){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        for(int i=0;i<5;i++){
            cout << nums[i] << " ";
        }
}