#include <iostream>
#include <queue>
using namespace std;

class stackk{
    queue <int> q1,q2;

    public:
        void push(int x){
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            swap(q1,q2);
        }
        int pop(){
            if(q1.empty()){
                cout << "empty";
            }
            return (q1.front());
        }
        int top(){
            cout << q1.front();
        }
        bool empty(){
            return q1.empty();
        }
        int main(){
            stackk s;
            s.push(3);
            s.push(4);
            cout << s.top();
            s.pop();
            cout << s.top();
        }
         
};

