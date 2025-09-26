#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main(){
    int arr[6] = {1,2,2,3,1,4};
    int ans,k=0;
    int maxfreq=0;
    int maxans=0;
    int sum=0;
    unordered_map <int,int> count;
    for(int i=0;i<6;i++){
        count[arr[i]]++;
        maxfreq = max(maxfreq,count[arr[i]]);
    }
    for(int i=0;i<6;i++){
        if(maxfreq == count[arr[i]]){
            sum+=count[arr[i]];
        }
    }
    for (auto &i : count) {
        if(i.second==maxfreq){
            k++;
        }
    }
    cout<<maxfreq*k;
}