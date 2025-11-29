#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        vector <int> freq(26,0);
        int max1 = 0, max2 = 0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20){
                max1 = max(max1,freq[i]);
            }
            else{
                max2 = max(max2,freq[i]);
            }
        }
        return max1 + max2;
    }
};

int main(){
    Solution s;
    cout << s.maxFreqSum("successes") << "\n";
}