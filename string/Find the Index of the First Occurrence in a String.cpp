#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()){
            return -1;
        }
        for(int i=0;i<=haystack.size()-needle.size();i++){
            if(haystack.substr(i,needle.size()) == needle){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s.strStr("sadbutsad","sad") << "\n";
}