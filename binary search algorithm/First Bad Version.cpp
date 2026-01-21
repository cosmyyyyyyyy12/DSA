#include <iostream>
using namespace std;

int BAD_VERSION = 4;

bool isBadVersion(int version) {
    return version >= BAD_VERSION;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int e = n;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (isBadVersion(mid)) {
                e = mid - 1; 
            } 
            else {
                s = mid + 1;   
            }
        }
        return s;  
    }
};

int main() {
    Solution sol;

    int n = 10;
    int result = sol.firstBadVersion(n);

    cout << "First bad version is: " << result << endl;

    return 0;
}
