#include <iostream>
using namespace std;

int subset(int arr[], int n, int x){
    if(x == 0){
        return 1;
    }
    if(x<0){
        return 0;
    }
    if (n<=0){
        return 0;
    }
    return subset(arr,n-1,x) + subset(arr,n,x-arr[n-1]);
}
int main(){
    int n = 3;
    int arr[n] = {1,2,3};
    int key = 4;
    int count = 0;
    cout << subset(arr,n,key);
}