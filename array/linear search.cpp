#include <iostream>
using namespace std;

void search(int arr[], int n,int key){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout << "element found";
            j=1;
            break;
        }
    }
    if(j==0){
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
    search(arr,n,key);
}