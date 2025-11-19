#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        int i = 0;
        while(i < address.size()){
            if(address[i] == '.'){
                ans += "[.]";
            }
            else{
                ans += address[i];
            }
            i++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.defangIPaddr("1.1.1.1") << "\n";
    cout << s.defangIPaddr("255.100.50.0");
}