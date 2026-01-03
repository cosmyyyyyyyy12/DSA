#include <iostream>
#include <queue>
using namespace std;

class Stack{
    queue <int> q1;
    int size = 0;

    public:
        void push(int x){
            q1.push(x);
            for(int i=0;i<size;i++){
                q1.push(q1.front());
                q1.pop();
            }
            size++;
        }

        int top(){
            return q1.front();
        }    
};
int main(){
    Stack s;
    s.push(3);
    s.push(4);
    cout << s.top();
}
