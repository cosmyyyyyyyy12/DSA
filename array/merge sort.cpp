#include <iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int n1 = m-l+1; //size of 1st subarray
    int n2 = r-m; // size of 2nd subarray
    
    int L[n1],R[n2]; // temp arrays
    
    // copy the data to temp arrays 
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[m+1+i];
    }
    
    int i=0,j=0,k=l;
    
    // merging temp arrays 
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }
    
    // copying remaining elements
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
}

void merge_sort(int arr[],int l,int r){
    if(l<r){
        int m = l + (r-l)/2;
        merge_sort(arr,l,m); // solves the 1st half
        merge_sort(arr,m+1,r); // solves the 2nd half
        merge(arr,l,m,r); // merges both of them
    }
}

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cout << "enter no. of elements";
    cin >> n;
    int arr[n];
    cout << "enter " << n << " no.s of elements";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    merge_sort(arr,0,n-1);
    cout << "sorted array";
    print_array(arr,n);
}