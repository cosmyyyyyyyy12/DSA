#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0){
            return false;
        }
        for(int i:{2,3,5}){
            while(n % i == 0){
                n = n/i;
            }
        }
        return n == 1;
    }
};

int main(){
    Solution s;
    cout << s.isUgly(6) << "\n";
}
