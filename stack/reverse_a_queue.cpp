#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    stack <int> st;
    queue <int> q;
    q.push(2);
    q.push(3);
    q.push(1);
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

}