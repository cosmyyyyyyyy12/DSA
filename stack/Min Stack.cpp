#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {

    }

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } 
        else {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack obj;

    obj.push(5);
    obj.push(3);
    obj.push(7);
    obj.push(2);

    cout << "top element:" << obj.top()
    cout << "min element" << obj.getMin()
}
