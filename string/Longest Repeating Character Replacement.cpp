#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <int,int> m;
        int i=0,j=0,ans=0;
        int mc = 0;
        while(j<s.size()){
            if(m.find(s[j]) != m.end()){
                m[s[j]]++;
            }
            else{
                m.insert({s[j],1});
            }
            int ws = j-i+1;
            for (auto it : m) {
                mc = max(mc, it.second);
            }
            if(ws-mc > k){
                m[s[i]]--;
                i++;
                ws--;
            }
            ans = max(ans,ws);
            j++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.characterReplacement("abcabcbb",2) << "\n";
}