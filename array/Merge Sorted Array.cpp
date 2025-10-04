#include <iostream>
#include <vector>
using namespace std;
int main(){
    int nums1[6] = {1,2,3,0,0,0}, m = 3, nums2[3] = {2,5,6}, n = 3;
    int r = m+n-1;
        int n1 = n-1, m1 = m-1;
        while(n1>=0){
            if(m1 >= 0 && nums1[m1]>nums2[n1]){
                nums1[r]=nums1[m1];
                m1--;
            }
            else{
                nums1[r]=nums2[n1];
                n1--;
            }
            r--;
        }
    for(int i = 0;i<m+n;i++){
        cout << nums1[i] << " ";
    }
}