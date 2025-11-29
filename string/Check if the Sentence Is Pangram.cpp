#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector <int> lower(26,0);
        for(int i=0; i<sentence.size(); i++){
            lower[sentence[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(lower[i] == 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.checkIfPangram("thequickbrownfoxjumpsoverthelazydog") << "\n";
}