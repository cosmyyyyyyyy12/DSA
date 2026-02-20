#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {

        if (n == 0) return 0;
        if (n == 1) return 1;

        int a = 0;
        int b = 1;
        int c;

        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

int main() {

    Solution sol;

    int n = 6;
    cout << "Fibonacci(" << n << ") = "
         << sol.fib(n);

    return 0;
}