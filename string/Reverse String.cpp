#include <iostream>
#include <vector>
using namespace std;
int main(){
    string s[5] = {"h","e","l","l","o"};
    int i=0;
        int j=4;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    for (int k = 0; k < 5; k++) {
        cout << s[k];
    }
}
