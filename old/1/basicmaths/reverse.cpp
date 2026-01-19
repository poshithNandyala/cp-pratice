#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;  // Use long long to handle overflow temporarily

        while (x != 0) {
            int rem = x % 10; // Get last digit
            x /= 10; // Remove last digit

            // Check for overflow before updating rev
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && rem > 7)) {
                return 0; // Overflow for positive numbers
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && rem < -8)) {
                return 0; // Overflow for negative numbers
            }

            rev = rev * 10 + rem;
        }
        return rev; // Return reversed value
    }
};

int main() {
    Solution solution;
    cout << solution.reverse(123) << endl;      // Output: 321
    cout << solution.reverse(-123) << endl;     // Output: -321
    cout << solution.reverse(1534236469) << endl; // Output: 0 (Overflow)
    cout << solution.reverse(-2147483648) << endl; // Output: 0 (Overflow)
    return 0;
}
