#include <iostream>
using namespace std;

void binary_search(int arr[], int n,int key){
    int beg=0;
    int end=n-1;
    int mid=beg+(end-beg)/2;
    int i = 0;
    while(beg<=end){
        if(arr[mid]==key){
            i=1;
            cout << "element found";
            break;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }
        mid=beg+(end-beg)/2;
    }
    if(i==0){
        cout << "element not found";
    }
}
int main() {
    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << "enter elemnt to be searched:";
    cin >> key;
    binary_search(arr,n,key);
}