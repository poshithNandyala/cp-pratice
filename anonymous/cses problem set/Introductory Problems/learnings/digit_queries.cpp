/*
QUESTION (brief):
-----------------
You are given a number n.
Imagine writing all positive integers continuously as a single sequence:

"123456789101112131415..."

Your task is to find the **n-th digit** in this infinite sequence.

Example:
n = 1 → '1'
n = 9 → '9'
n = 10 → '1'  (from "10")
n = 11 → '0'
*/

#include <bits/stdc++.h>
using namespace std;

// Use long long everywhere (safe for large n)
#define int long long
#define endl '\n'

// Fast input-output
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    fastio

    int t;          // number of test cases
    cin >> t;

    while (t--) {
        int n;      // we need to find the n-th digit
        cin >> n;

        /*
        digits = number of digits in numbers of the current block
        Example:
        digits = 1 → numbers: 1 to 9
        digits = 2 → numbers: 10 to 99
        digits = 3 → numbers: 100 to 999
        */
        int digits = 1;

        /*
        count = how many numbers are there with 'digits' digits
        1-digit → 9 numbers
        2-digit → 90 numbers
        3-digit → 900 numbers
        */
        int count = 9;

        /*
        start = position in the big digit sequence
        start tells where the current block begins
        */
        int start = 1;

        /*
        Move block by block until n lies inside a block
        Total digits in a block = count * digits

        Example:
        1-digit block → 9 * 1 = 9 digits
        2-digit block → 90 * 2 = 180 digits
        */
        while (n > start + count * digits - 1) {
            start += count * digits;  // skip this entire block
            count *= 10;              // next block has 10x numbers
            digits++;                 // digit length increases
        }

        /*
        st = smallest number with 'digits' digits
        digits = 1 → st = 1
        digits = 2 → st = 10
        digits = 3 → st = 100
        */
        int st = pow(10, digits - 1);

        /*
        num_offset = how many full numbers ahead inside this block
        */
        int num_offset = (n - start) / digits;

        /*
        num = the actual number that contains the answer digit
        */
        int num = st + num_offset;

        /*
        digit_offset = which digit inside 'num' we want
        */
        int digit_offset = (n - start) % digits;

        /*
        Convert number to string and print the required digit
        */
        cout << to_string(num)[digit_offset] << endl;
    }

    return 0;
}
