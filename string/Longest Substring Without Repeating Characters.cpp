#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map <int,int> m;
        int i=0,j=0,ans=1;
        if(s.empty()){
            return 0;
        }
        while(j<s.size()){
            if(i == j){
                m.insert({s[j],1});
            }
            else{
                if(m.find(s[j]) != m.end()){
                    m[s[j]]++;
                    while(m[s[j]] != 1){
                        m[s[i]]--;
                        i++;
                    }
                }
                else{
                    m.insert({s[j],1});
                }
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << "\n";
}