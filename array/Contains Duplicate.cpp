#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    int nums[4] = {1,2,3,1};
    unordered_map <int,int> count;
    for(int i=0;i<4;i++){
        count[nums[i]]++;
    }
    for(auto &i:count){
        if(i.second>=2){
            cout << "true";
        }
    }

}
