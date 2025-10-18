#include <iostream>
using namespace std;

int main() {
    int nums[3]={3,0,1};
    int n = 3;
        for(int i=0;i<3;i++){
            n+=i-nums[i];
        }
        cout << n;
}