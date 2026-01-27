#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void lpsfind(vector <int> &lps,string needle){
        int p = 0;
        int s = 1;
        while(s<needle.size()){
            //match
            if(needle[p] == needle[s]){
                lps[s] = p+1;
                p++;
                s++;
            }
            //not matched
            else{
                if(p == 0){
                    lps[s] = 0;
                    s++;
                }
                else{
                    p = lps[p-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.empty()){
            return 0;
        } 
        if (needle.size() > haystack.size()){
            return -1;
        }
        
        vector <int> lps(needle.size(),0);
        lpsfind(lps,needle);
        int i = 0;
        int j = 0;
        while(i<haystack.size() && j<needle.size()){
            if(haystack[i] == needle[j]){
                i++,j++;
            }
            if (j == needle.size()) {
                return i - j;
            } 
            else if (i < haystack.size() && haystack[i] != needle[j]) {
                if (j == 0){ 
                    i++;
                }
                else {
                    j = lps[j - 1];
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s.strStr("sadbutsad","sad") << "\n";
}