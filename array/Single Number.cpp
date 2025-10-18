#include <iostream>
using namespace std;

int main() {
    int nums[3]={2,2,1};
    int sum=nums[0];
        for(int i=1;i<3;i++){
            sum^=nums[i];
        }
        cout << sum;
}
