#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int r = 0,l = 0,i = 0,cnt = 0;
        while(i<s.size()){
            if(s[i] == 'R'){
                r++;
            }
            if(s[i] == 'L'){
                l++;
            }
            if(r == l && r>0){
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};

int main(){
    Solution s;
    cout << s.balancedStringSplit("RLRRLLRLRL") << "\n";
}