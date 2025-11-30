#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0){
            return false;
        }
        while(n % 4 == 0){
            n/=4;
        }
        return n == 1;
    }
};

int main(){
    Solution s;
    cout << s.isPowerOfThree(16) << "\n";
}