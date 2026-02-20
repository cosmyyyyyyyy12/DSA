#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        reverse(digits.begin(), digits.end());

        int i;

        if (digits[0] != 9) {
            digits[0]++;
        }
        else {
            for (i = 0; i < digits.size(); i++) {

                if (digits[i] == 9) {
                    digits[i] = 0;
                }
                else {
                    digits[i]++;
                    break;
                }
            }
        }

        // Check if all digits became 0
        bool allZero = true;
        for (int j = 0; j < digits.size(); j++) {
            if (digits[j] != 0) {
                allZero = false;
                break;
            }
        }

        if (allZero) {
            digits.push_back(1);
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }
};

int main() {

    Solution sol;

    vector<int> digits = {9, 9, 9};

    vector<int> result = sol.plusOne(digits);

    cout << "Result: ";
    for (int x : result)
        cout << x << " ";

    return 0;
}