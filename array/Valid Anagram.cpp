#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    string s = "dgqztusjuu",t = "dqugjzutsu";
    unordered_map <char,int> count1;
    unordered_map <char,int> count2;
    for(int i=0;i<10;i++){
        count1[s[i]]++;
    }
    for(int i=0;i<10;i++){
        count2[t[i]]++;
    }
    
    if(count1==count2){
        cout<<"true";
    }
}