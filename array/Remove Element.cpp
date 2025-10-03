#include <iostream>
#include <vector>
using namespace std;
int main(){
    int nums[4] = {3,2,2,3},val=3;
    int i=0,j;
        for(j=0;j<4;j++){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
            }
        }
        cout << i;
}