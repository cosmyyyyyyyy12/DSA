#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < s.size(); i += 2 * k) {
            int end = min(i + k, n);
            reverse(s.begin() + i, s.begin() + end);
        }
        return s;
    }
};

int main(){
    Solution s;
    cout << s.reverseStr("abcdefg",2) << "\n";
}