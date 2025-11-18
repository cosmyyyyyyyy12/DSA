#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector <int> lower(26,0), upper(26,0);
        for(int i=0;i<s.size();i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                lower[s[i]-'a']++;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                upper[s[i]-'A']++;
            }
        }
        int cnt = 0;
        int odd = 0;
        for(int i=0;i<26;i++){
            if(lower[i] % 2 == 0){
                cnt += lower[i];
            }
            else{
                cnt += lower[i]-1;
                odd = 1;
            }
        }
        for(int i=0;i<26;i++){
            if(upper[i] % 2 == 0){
                cnt += upper[i];
            }
            else{
                cnt += upper[i]-1;
                odd = 1;
            }
        }
        return cnt+odd;
    }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("abccccdd") << "\n";
    cout << s.longestPalindrome("a");
}