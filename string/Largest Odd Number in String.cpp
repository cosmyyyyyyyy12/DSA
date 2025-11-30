#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size();i>=0;i--){
            int ans = num[i] - '0';
            if(ans % 2 != 0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};

int main(){
    Solution s;
    cout << s.largestOddNumber("52") << "\n";
}