#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s = "hello";
    stack <char> st;
    for(char c : s){
        st.push(c);
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}