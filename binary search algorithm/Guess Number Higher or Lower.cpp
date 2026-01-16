#include <iostream>
using namespace std;

int PICKED_NUMBER = 6;

int guess(int num) {
    if (num > PICKED_NUMBER) return -1;
    if (num < PICKED_NUMBER) return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int s = 1;
        int e = n;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (guess(mid) == 0) {
                return mid;
            } 
            else if (guess(mid) == -1) {
                e = mid - 1;
            } 
            else {
                s = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n = 10;

    int result = sol.guessNumber(n);
    cout << "Picked number is: " << result << endl;

    return 0;
}
