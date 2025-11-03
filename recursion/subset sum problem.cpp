#include <iostream>
using namespace std;

bool subset(int arr[], int n, int x){
    if(x == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(arr[0]>x){
        return (subset(arr+1, n-1, x));
    }
    else{
        return (subset(arr+1, n-1, x-arr[0]) || subset(arr+1, n-1, x));
    }
}
int main(){
    int n = 4;
    int arr[n] = {3,2,7,1};
    int key = 6;
    if(subset(arr,n,key)){
        cout << "true";
    }
    else{
        cout << "false";
    }
}