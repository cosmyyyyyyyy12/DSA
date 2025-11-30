#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map <char,int> sstring;
        unordered_map <char,int> tstring;
        for(int i=0;i<s.size();i++){
            if(sstring.find(s[i]) == sstring.end()){
                sstring[s[i]] = i;
            }
            if(tstring.find(t[i]) == tstring.end()){
                tstring[t[i]] = i;
            }
            if(sstring[s[i]] != tstring[t[i]]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.isIsomorphic("egg","add") << "\n";
}