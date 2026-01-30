#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0),freq2(26,0);

        int i = 0;

        for(int i=0;i<s1.size();i++){
            freq1[s1[i] - 'a']++;
        }
        
        if (s1.size() > s2.size()){
            return false;
        }

        for(int j=0;j<s2.size();j++){
            freq2[s2[j] - 'a']++;
            if(j-i+1>s1.size()){
                freq2[s2[i] - 'a']--;
                i++;
            }
            if(freq1 == freq2){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << s.checkInclusion("ab","eidbaooo") << "\n";
}