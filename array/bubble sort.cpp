#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "enter no. of elements";
    cin >> n;
    int arr[n];
    cout << "enter " << n << " no. of elements";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}