#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
            }
        arr[j+1] = temp;
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    insertion_sort(arr, n);
}